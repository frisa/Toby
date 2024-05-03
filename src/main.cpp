#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    QVBoxLayout layout(&window);

    QLabel label("Toby application");
    layout.addWidget(&label);

    QLineEdit textbox;
    textbox.setText("Hello World");
    layout.addWidget(&textbox);

    QPushButton button("Click me");
    layout.addWidget(&button);

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        QMessageBox::information(&window, "Information", textbox.text());
    });

    window.show();
    return app.exec();
}