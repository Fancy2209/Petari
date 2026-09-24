#ifndef NW4R_UT_ROMFONT_H_
#define NW4R_UT_ROMFONT_H_

#include <revolution/types.h>
#include "nw4r/ut/Font.h"

namespace nw4r {
    namespace ut {

        class RomFont : public Font {
        public:
            RomFont();
            virtual ~RomFont();

            bool Load(void* buffer);
            void* Unload();
            static u32 GetRequireBufferSize();

            virtual int GetWidth() const ATTRIBUTE_WEAK;
            virtual int GetHeight() const ATTRIBUTE_WEAK;
            virtual int GetAscent() const ATTRIBUTE_WEAK;
            virtual int GetDescent() const ATTRIBUTE_WEAK;
            virtual int GetBaselinePos() const ATTRIBUTE_WEAK;
            virtual int GetCellHeight() const ATTRIBUTE_WEAK;
            virtual int GetCellWidth() const ATTRIBUTE_WEAK;
            virtual int GetMaxCharWidth() const ATTRIBUTE_WEAK;
            virtual Type GetType() const ATTRIBUTE_WEAK;
            virtual GXTexFmt GetTextureFormat() const ATTRIBUTE_WEAK;
            virtual int GetLineFeed() const ATTRIBUTE_WEAK;
            virtual const CharWidths GetDefaultCharWidths() const ATTRIBUTE_WEAK;

            virtual void SetDefaultCharWidths(const CharWidths& widths) ATTRIBUTE_WEAK;

            virtual bool SetAlternateChar(CharCode c) ATTRIBUTE_WEAK;

            virtual void SetLineFeed(int linefeed) ATTRIBUTE_WEAK;

            virtual int GetCharWidth(CharCode c) const ATTRIBUTE_WEAK;

            virtual const CharWidths GetCharWidths(CharCode c) const ATTRIBUTE_WEAK;

            virtual void GetGlyph(Glyph* glyphPtr, CharCode c) const ATTRIBUTE_WEAK;

            virtual bool HasGlyph(CharCode c) const ATTRIBUTE_WEAK;

            virtual FontEncoding GetEncoding() const ATTRIBUTE_WEAK;

        private:
            const static int CHAR_PTR_BUFFER_SIZE = 3;

            static u16 mFontEncode;
            OSFontHeader* mFontHeader;
            CharWidths mDefaultWidths;
            CharCode mAlternateChar;

            void MakeCharPtr(char* buffer, CharCode c) const;

            CharCode HandleUndefinedChar(CharCode c) const;
        };

    }
}
#endif
