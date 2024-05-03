#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

#include <unistd.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("PC Informations");
    QVBoxLayout layout(&window);

    char hostname[1024];
    gethostname(hostname, 1024);
    QString hostName = QString::fromUtf8(hostname);
    QLabel label("Host Name: " + hostName);
    layout.addWidget(&label);

    char username[1024];
    getlogin_r(username, 1024);
    QString userName = QString::fromUtf8(username);
    QLabel label2("User Name: " + userName);
    layout.addWidget(&label2);

    char cwd[1024];
    getcwd(cwd, 1024);
    QString currentDir = QString::fromUtf8(cwd);
    QLabel label3("Current Directory: " + currentDir);
    layout.addWidget(&label3);

    std::array<char, 128> buffer;
    std::string result;
    FILE *pipe = popen("sysctl -n machdep.cpu.brand_string", "r");
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr)
    {
        result += buffer.data();
    }
    pclose(pipe);
    QString cpuInfo = QString::fromUtf8(result);
    QLabel label4("CPU Info: " + cpuInfo);
    layout.addWidget(&label4);

    QLineEdit textbox;
    textbox.setText("Enter your name: ");
    layout.addWidget(&textbox);

    QPushButton button("Show Information");
    layout.addWidget(&button);

    QObject::connect(&button, &QPushButton::clicked, [&]()
                     { QMessageBox::information(&window, "Information", textbox.text()); });

    window.show();
    return app.exec();
}