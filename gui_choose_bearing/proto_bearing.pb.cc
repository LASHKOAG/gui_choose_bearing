// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto_bearing.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto_bearing.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace package_bearing {

namespace {

const ::google::protobuf::Descriptor* Message_bearing_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Message_bearing_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_5fbearing_2eproto() {
  protobuf_AddDesc_proto_5fbearing_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto_bearing.proto");
  GOOGLE_CHECK(file != NULL);
  Message_bearing_descriptor_ = file->message_type(0);
  static const int Message_bearing_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_diameter_outer_race_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_diameter_inner_race_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_diameter_roller_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_roller_angle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, bearing_roller_number_),
  };
  Message_bearing_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Message_bearing_descriptor_,
      Message_bearing::default_instance_,
      Message_bearing_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Message_bearing, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Message_bearing));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_5fbearing_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Message_bearing_descriptor_, &Message_bearing::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_5fbearing_2eproto() {
  delete Message_bearing::default_instance_;
  delete Message_bearing_reflection_;
}

void protobuf_AddDesc_proto_5fbearing_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023proto_bearing.proto\022\017package_bearing\"\317"
    "\001\n\017Message_bearing\022\024\n\014bearing_name\030\001 \001(\t"
    "\022#\n\033bearing_diameter_outer_race\030\002 \001(\005\022#\n"
    "\033bearing_diameter_inner_race\030\003 \001(\005\022\037\n\027be"
    "aring_diameter_roller\030\004 \001(\005\022\034\n\024bearing_r"
    "oller_angle\030\005 \001(\002\022\035\n\025bearing_roller_numb"
    "er\030\006 \001(\005", 248);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto_bearing.proto", &protobuf_RegisterTypes);
  Message_bearing::default_instance_ = new Message_bearing();
  Message_bearing::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_5fbearing_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_5fbearing_2eproto {
  StaticDescriptorInitializer_proto_5fbearing_2eproto() {
    protobuf_AddDesc_proto_5fbearing_2eproto();
  }
} static_descriptor_initializer_proto_5fbearing_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Message_bearing::kBearingNameFieldNumber;
const int Message_bearing::kBearingDiameterOuterRaceFieldNumber;
const int Message_bearing::kBearingDiameterInnerRaceFieldNumber;
const int Message_bearing::kBearingDiameterRollerFieldNumber;
const int Message_bearing::kBearingRollerAngleFieldNumber;
const int Message_bearing::kBearingRollerNumberFieldNumber;
#endif  // !_MSC_VER

Message_bearing::Message_bearing()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:package_bearing.Message_bearing)
}

void Message_bearing::InitAsDefaultInstance() {
}

Message_bearing::Message_bearing(const Message_bearing& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:package_bearing.Message_bearing)
}

void Message_bearing::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  bearing_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  bearing_diameter_outer_race_ = 0;
  bearing_diameter_inner_race_ = 0;
  bearing_diameter_roller_ = 0;
  bearing_roller_angle_ = 0;
  bearing_roller_number_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Message_bearing::~Message_bearing() {
  // @@protoc_insertion_point(destructor:package_bearing.Message_bearing)
  SharedDtor();
}

void Message_bearing::SharedDtor() {
  if (bearing_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete bearing_name_;
  }
  if (this != default_instance_) {
  }
}

void Message_bearing::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Message_bearing::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Message_bearing_descriptor_;
}

const Message_bearing& Message_bearing::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_5fbearing_2eproto();
  return *default_instance_;
}

Message_bearing* Message_bearing::default_instance_ = NULL;

Message_bearing* Message_bearing::New() const {
  return new Message_bearing;
}

void Message_bearing::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Message_bearing*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 63) {
    ZR_(bearing_diameter_outer_race_, bearing_roller_number_);
    if (has_bearing_name()) {
      if (bearing_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        bearing_name_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Message_bearing::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:package_bearing.Message_bearing)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string bearing_name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_bearing_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->bearing_name().data(), this->bearing_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "bearing_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_bearing_diameter_outer_race;
        break;
      }

      // optional int32 bearing_diameter_outer_race = 2;
      case 2: {
        if (tag == 16) {
         parse_bearing_diameter_outer_race:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &bearing_diameter_outer_race_)));
          set_has_bearing_diameter_outer_race();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_bearing_diameter_inner_race;
        break;
      }

      // optional int32 bearing_diameter_inner_race = 3;
      case 3: {
        if (tag == 24) {
         parse_bearing_diameter_inner_race:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &bearing_diameter_inner_race_)));
          set_has_bearing_diameter_inner_race();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_bearing_diameter_roller;
        break;
      }

      // optional int32 bearing_diameter_roller = 4;
      case 4: {
        if (tag == 32) {
         parse_bearing_diameter_roller:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &bearing_diameter_roller_)));
          set_has_bearing_diameter_roller();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(45)) goto parse_bearing_roller_angle;
        break;
      }

      // optional float bearing_roller_angle = 5;
      case 5: {
        if (tag == 45) {
         parse_bearing_roller_angle:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &bearing_roller_angle_)));
          set_has_bearing_roller_angle();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_bearing_roller_number;
        break;
      }

      // optional int32 bearing_roller_number = 6;
      case 6: {
        if (tag == 48) {
         parse_bearing_roller_number:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &bearing_roller_number_)));
          set_has_bearing_roller_number();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:package_bearing.Message_bearing)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:package_bearing.Message_bearing)
  return false;
#undef DO_
}

void Message_bearing::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:package_bearing.Message_bearing)
  // optional string bearing_name = 1;
  if (has_bearing_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->bearing_name().data(), this->bearing_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "bearing_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->bearing_name(), output);
  }

  // optional int32 bearing_diameter_outer_race = 2;
  if (has_bearing_diameter_outer_race()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->bearing_diameter_outer_race(), output);
  }

  // optional int32 bearing_diameter_inner_race = 3;
  if (has_bearing_diameter_inner_race()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->bearing_diameter_inner_race(), output);
  }

  // optional int32 bearing_diameter_roller = 4;
  if (has_bearing_diameter_roller()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->bearing_diameter_roller(), output);
  }

  // optional float bearing_roller_angle = 5;
  if (has_bearing_roller_angle()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->bearing_roller_angle(), output);
  }

  // optional int32 bearing_roller_number = 6;
  if (has_bearing_roller_number()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->bearing_roller_number(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:package_bearing.Message_bearing)
}

::google::protobuf::uint8* Message_bearing::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:package_bearing.Message_bearing)
  // optional string bearing_name = 1;
  if (has_bearing_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->bearing_name().data(), this->bearing_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "bearing_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->bearing_name(), target);
  }

  // optional int32 bearing_diameter_outer_race = 2;
  if (has_bearing_diameter_outer_race()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->bearing_diameter_outer_race(), target);
  }

  // optional int32 bearing_diameter_inner_race = 3;
  if (has_bearing_diameter_inner_race()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->bearing_diameter_inner_race(), target);
  }

  // optional int32 bearing_diameter_roller = 4;
  if (has_bearing_diameter_roller()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->bearing_diameter_roller(), target);
  }

  // optional float bearing_roller_angle = 5;
  if (has_bearing_roller_angle()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->bearing_roller_angle(), target);
  }

  // optional int32 bearing_roller_number = 6;
  if (has_bearing_roller_number()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->bearing_roller_number(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:package_bearing.Message_bearing)
  return target;
}

int Message_bearing::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string bearing_name = 1;
    if (has_bearing_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->bearing_name());
    }

    // optional int32 bearing_diameter_outer_race = 2;
    if (has_bearing_diameter_outer_race()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->bearing_diameter_outer_race());
    }

    // optional int32 bearing_diameter_inner_race = 3;
    if (has_bearing_diameter_inner_race()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->bearing_diameter_inner_race());
    }

    // optional int32 bearing_diameter_roller = 4;
    if (has_bearing_diameter_roller()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->bearing_diameter_roller());
    }

    // optional float bearing_roller_angle = 5;
    if (has_bearing_roller_angle()) {
      total_size += 1 + 4;
    }

    // optional int32 bearing_roller_number = 6;
    if (has_bearing_roller_number()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->bearing_roller_number());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Message_bearing::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Message_bearing* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Message_bearing*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Message_bearing::MergeFrom(const Message_bearing& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_bearing_name()) {
      set_bearing_name(from.bearing_name());
    }
    if (from.has_bearing_diameter_outer_race()) {
      set_bearing_diameter_outer_race(from.bearing_diameter_outer_race());
    }
    if (from.has_bearing_diameter_inner_race()) {
      set_bearing_diameter_inner_race(from.bearing_diameter_inner_race());
    }
    if (from.has_bearing_diameter_roller()) {
      set_bearing_diameter_roller(from.bearing_diameter_roller());
    }
    if (from.has_bearing_roller_angle()) {
      set_bearing_roller_angle(from.bearing_roller_angle());
    }
    if (from.has_bearing_roller_number()) {
      set_bearing_roller_number(from.bearing_roller_number());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Message_bearing::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Message_bearing::CopyFrom(const Message_bearing& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message_bearing::IsInitialized() const {

  return true;
}

void Message_bearing::Swap(Message_bearing* other) {
  if (other != this) {
    std::swap(bearing_name_, other->bearing_name_);
    std::swap(bearing_diameter_outer_race_, other->bearing_diameter_outer_race_);
    std::swap(bearing_diameter_inner_race_, other->bearing_diameter_inner_race_);
    std::swap(bearing_diameter_roller_, other->bearing_diameter_roller_);
    std::swap(bearing_roller_angle_, other->bearing_roller_angle_);
    std::swap(bearing_roller_number_, other->bearing_roller_number_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Message_bearing::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Message_bearing_descriptor_;
  metadata.reflection = Message_bearing_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace package_bearing

// @@protoc_insertion_point(global_scope)
