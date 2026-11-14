;
; ------------------------------------------------------------
;
;   PureBasic - File example file
;
;    (c) Fantaisie Software
;
; ------------------------------------------------------------
;

XIncludeFile "libxl.pb"

book = xlCreateXMLBook()

sheet = xlBookAddSheet(book, "sheet1")

myfont = xlBookAddFont(book)
xlFontSetSize(myfont, 22)
xlFontSetName(myfont, "Arial")
xlFontSetColor(myfont, #COLOR_ORANGE)
xlFontSetBold(myfont)
xlFontSetItalic(myfont)
xlFontSetUnderline(myfont)

f = xlBookAddFormat(book)
xlFormatSetFillPattern(f, #FILLPATTERN_SOLID)
xlFormatSetPatternForegroundColor(f, #COLOR_LIGHTYELLOW)
xlFormatSetFont(f, myfont)

xlSheetWriteStr(sheet, 2, 1, "Arial", f)

xlSheetWriteNum(sheet, 5, 1, 100)
xlSheetWriteNum(sheet, 6, 1, 200)
xlSheetWriteNum(sheet, 7, 1, 300)
xlSheetWriteNum(sheet, 8, 1, 400)

xlBookSave(book, "out.xlsx")

xlBookRelease(book)

End



; IDE Options = PureBasic 6.21 (Windows - x64)
; CursorPosition = 34
; FirstLine = 3
; EnableXP
; DPIAware