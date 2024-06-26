// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sensor.proto
// Protobuf C++ Version: 5.26.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_sensor_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_sensor_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 5026001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_sensor_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_sensor_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_sensor_2eproto;
namespace sensor {
class SensorReply;
struct SensorReplyDefaultTypeInternal;
extern SensorReplyDefaultTypeInternal _SensorReply_default_instance_;
class SensorRequest;
struct SensorRequestDefaultTypeInternal;
extern SensorRequestDefaultTypeInternal _SensorRequest_default_instance_;
}  // namespace sensor
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace sensor {

// ===================================================================


// -------------------------------------------------------------------

class SensorRequest final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:sensor.SensorRequest) */ {
 public:
  inline SensorRequest() : SensorRequest(nullptr) {}
  ~SensorRequest() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR SensorRequest(
      ::google::protobuf::internal::ConstantInitialized);

  inline SensorRequest(const SensorRequest& from) : SensorRequest(nullptr, from) {}
  inline SensorRequest(SensorRequest&& from) noexcept
      : SensorRequest(nullptr, std::move(from)) {}
  inline SensorRequest& operator=(const SensorRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SensorRequest& operator=(SensorRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SensorRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const SensorRequest* internal_default_instance() {
    return reinterpret_cast<const SensorRequest*>(
        &_SensorRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(SensorRequest& a, SensorRequest& b) { a.Swap(&b); }
  inline void Swap(SensorRequest* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SensorRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SensorRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<SensorRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SensorRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const SensorRequest& from) { SensorRequest::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(SensorRequest* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "sensor.SensorRequest"; }

 protected:
  explicit SensorRequest(::google::protobuf::Arena* arena);
  SensorRequest(::google::protobuf::Arena* arena, const SensorRequest& from);
  SensorRequest(::google::protobuf::Arena* arena, SensorRequest&& from) noexcept
      : SensorRequest(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kCommandFieldNumber = 1,
  };
  // string command = 1;
  void clear_command() ;
  const std::string& command() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_command(Arg_&& arg, Args_... args);
  std::string* mutable_command();
  PROTOBUF_NODISCARD std::string* release_command();
  void set_allocated_command(std::string* value);

  private:
  const std::string& _internal_command() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_command(
      const std::string& value);
  std::string* _internal_mutable_command();

  public:
  // @@protoc_insertion_point(class_scope:sensor.SensorRequest)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      36, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::ArenaStringPtr command_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_sensor_2eproto;
};
// -------------------------------------------------------------------

class SensorReply final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:sensor.SensorReply) */ {
 public:
  inline SensorReply() : SensorReply(nullptr) {}
  ~SensorReply() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR SensorReply(
      ::google::protobuf::internal::ConstantInitialized);

  inline SensorReply(const SensorReply& from) : SensorReply(nullptr, from) {}
  inline SensorReply(SensorReply&& from) noexcept
      : SensorReply(nullptr, std::move(from)) {}
  inline SensorReply& operator=(const SensorReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline SensorReply& operator=(SensorReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SensorReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const SensorReply* internal_default_instance() {
    return reinterpret_cast<const SensorReply*>(
        &_SensorReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(SensorReply& a, SensorReply& b) { a.Swap(&b); }
  inline void Swap(SensorReply* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SensorReply* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SensorReply* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<SensorReply>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SensorReply& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const SensorReply& from) { SensorReply::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(SensorReply* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "sensor.SensorReply"; }

 protected:
  explicit SensorReply(::google::protobuf::Arena* arena);
  SensorReply(::google::protobuf::Arena* arena, const SensorReply& from);
  SensorReply(::google::protobuf::Arena* arena, SensorReply&& from) noexcept
      : SensorReply(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kLatitudeFieldNumber = 1,
    kLongitudeFieldNumber = 2,
  };
  // int32 latitude = 1;
  void clear_latitude() ;
  ::int32_t latitude() const;
  void set_latitude(::int32_t value);

  private:
  ::int32_t _internal_latitude() const;
  void _internal_set_latitude(::int32_t value);

  public:
  // int32 longitude = 2;
  void clear_longitude() ;
  ::int32_t longitude() const;
  void set_longitude(::int32_t value);

  private:
  ::int32_t _internal_longitude() const;
  void _internal_set_longitude(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:sensor.SensorReply)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::int32_t latitude_;
    ::int32_t longitude_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_sensor_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// SensorRequest

// string command = 1;
inline void SensorRequest::clear_command() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.command_.ClearToEmpty();
}
inline const std::string& SensorRequest::command() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:sensor.SensorRequest.command)
  return _internal_command();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void SensorRequest::set_command(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.command_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:sensor.SensorRequest.command)
}
inline std::string* SensorRequest::mutable_command() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_command();
  // @@protoc_insertion_point(field_mutable:sensor.SensorRequest.command)
  return _s;
}
inline const std::string& SensorRequest::_internal_command() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.command_.Get();
}
inline void SensorRequest::_internal_set_command(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.command_.Set(value, GetArena());
}
inline std::string* SensorRequest::_internal_mutable_command() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _impl_.command_.Mutable( GetArena());
}
inline std::string* SensorRequest::release_command() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:sensor.SensorRequest.command)
  return _impl_.command_.Release();
}
inline void SensorRequest::set_allocated_command(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.command_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.command_.IsDefault()) {
          _impl_.command_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:sensor.SensorRequest.command)
}

// -------------------------------------------------------------------

// SensorReply

// int32 latitude = 1;
inline void SensorReply::clear_latitude() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.latitude_ = 0;
}
inline ::int32_t SensorReply::latitude() const {
  // @@protoc_insertion_point(field_get:sensor.SensorReply.latitude)
  return _internal_latitude();
}
inline void SensorReply::set_latitude(::int32_t value) {
  _internal_set_latitude(value);
  // @@protoc_insertion_point(field_set:sensor.SensorReply.latitude)
}
inline ::int32_t SensorReply::_internal_latitude() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.latitude_;
}
inline void SensorReply::_internal_set_latitude(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.latitude_ = value;
}

// int32 longitude = 2;
inline void SensorReply::clear_longitude() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.longitude_ = 0;
}
inline ::int32_t SensorReply::longitude() const {
  // @@protoc_insertion_point(field_get:sensor.SensorReply.longitude)
  return _internal_longitude();
}
inline void SensorReply::set_longitude(::int32_t value) {
  _internal_set_longitude(value);
  // @@protoc_insertion_point(field_set:sensor.SensorReply.longitude)
}
inline ::int32_t SensorReply::_internal_longitude() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.longitude_;
}
inline void SensorReply::_internal_set_longitude(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.longitude_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace sensor


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_sensor_2eproto_2epb_2eh
