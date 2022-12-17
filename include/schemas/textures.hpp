// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TEXTURES_H_
#define FLATBUFFERS_GENERATED_TEXTURES_H_

#include "flatbuffers/flatbuffers.h"

struct TextureRoot;
struct TextureRootBuilder;

struct Texture;
struct TextureBuilder;

struct TextureRoot FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TextureRootBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TEXTURES = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<Texture>> *textures() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Texture>> *>(VT_TEXTURES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TEXTURES) &&
           verifier.VerifyVector(textures()) &&
           verifier.VerifyVectorOfTables(textures()) &&
           verifier.EndTable();
  }
};

struct TextureRootBuilder {
  typedef TextureRoot Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_textures(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Texture>>> textures) {
    fbb_.AddOffset(TextureRoot::VT_TEXTURES, textures);
  }
  explicit TextureRootBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<TextureRoot> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TextureRoot>(end);
    return o;
  }
};

inline flatbuffers::Offset<TextureRoot> CreateTextureRoot(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Texture>>> textures = 0) {
  TextureRootBuilder builder_(_fbb);
  builder_.add_textures(textures);
  return builder_.Finish();
}

inline flatbuffers::Offset<TextureRoot> CreateTextureRootDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<flatbuffers::Offset<Texture>> *textures = nullptr) {
  auto textures__ = textures ? _fbb.CreateVectorOfSortedTables<Texture>(textures) : 0;
  return CreateTextureRoot(
      _fbb,
      textures__);
}

struct Texture FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TextureBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TYPE = 4,
    VT_PATH = 6
  };
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  bool KeyCompareLessThan(const Texture *o) const {
    return *type() < *o->type();
  }
  int KeyCompareWithValue(const char *_type) const {
    return strcmp(type()->c_str(), _type);
  }
  const flatbuffers::String *path() const {
    return GetPointer<const flatbuffers::String *>(VT_PATH);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TYPE) &&
           verifier.VerifyString(type()) &&
           VerifyOffset(verifier, VT_PATH) &&
           verifier.VerifyString(path()) &&
           verifier.EndTable();
  }
};

struct TextureBuilder {
  typedef Texture Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(Texture::VT_TYPE, type);
  }
  void add_path(flatbuffers::Offset<flatbuffers::String> path) {
    fbb_.AddOffset(Texture::VT_PATH, path);
  }
  explicit TextureBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Texture> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Texture>(end);
    fbb_.Required(o, Texture::VT_TYPE);
    return o;
  }
};

inline flatbuffers::Offset<Texture> CreateTexture(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> type = 0,
    flatbuffers::Offset<flatbuffers::String> path = 0) {
  TextureBuilder builder_(_fbb);
  builder_.add_path(path);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Texture> CreateTextureDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *type = nullptr,
    const char *path = nullptr) {
  auto type__ = type ? _fbb.CreateString(type) : 0;
  auto path__ = path ? _fbb.CreateString(path) : 0;
  return CreateTexture(
      _fbb,
      type__,
      path__);
}

inline const TextureRoot *GetTextureRoot(const void *buf) {
  return flatbuffers::GetRoot<TextureRoot>(buf);
}

inline const TextureRoot *GetSizePrefixedTextureRoot(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<TextureRoot>(buf);
}

inline bool VerifyTextureRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<TextureRoot>(nullptr);
}

inline bool VerifySizePrefixedTextureRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<TextureRoot>(nullptr);
}

inline void FinishTextureRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<TextureRoot> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTextureRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<TextureRoot> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_TEXTURES_H_
