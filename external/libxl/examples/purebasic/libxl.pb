;///////////////////////////////////////////////////////////////////////////////
;//                                                                           //
;//                  LibXL PureBasic headers version 5.2.0                    //
;//                                                                           //
;//                 Copyright (c) 2008 - 2026 XLware s.r.o.                   //
;//                                                                           //
;//   THIS FILE And THE SOFTWARE CONTAINED HEREIN IS PROVIDED 'AS IS' And     //
;//                COMES With NO WARRANTIES OF ANY KIND.                      //
;//                                                                           // 
;///////////////////////////////////////////////////////////////////////////////

Enumeration Color 
    #COLOR_BLACK = 8
    #COLOR_WHITE
    #COLOR_RED
    #COLOR_BRIGHTGREEN
    #COLOR_BLUE
    #COLOR_YELLOW
    #COLOR_PINK
    #COLOR_TURQUOISE
    #COLOR_DARKRED
    #COLOR_GREEN
    #COLOR_DARKBLUE
    #COLOR_DARKYELLOW
    #COLOR_VIOLET
    #COLOR_TEAL
    #COLOR_GRAY25
    #COLOR_GRAY50
    #COLOR_PERIWINKLE_CF
    #COLOR_PLUM_CF
    #COLOR_IVORY_CF
    #COLOR_LIGHTTURQUOISE_CF
    #COLOR_DARKPURPLE_CF
    #COLOR_CORAL_CF
    #COLOR_OCEANBLUE_CF
    #COLOR_ICEBLUE_CF
    #COLOR_DARKBLUE_CL
    #COLOR_PINK_CL
    #COLOR_YELLOW_CL
    #COLOR_TURQUOISE_CL
    #COLOR_VIOLET_CL
    #COLOR_DARKRED_CL
    #COLOR_TEAL_CL
    #COLOR_BLUE_CL
    #COLOR_SKYBLUE
    #COLOR_LIGHTTURQUOISE
    #COLOR_LIGHTGREEN
    #COLOR_LIGHTYELLOW
    #COLOR_PALEBLUE
    #COLOR_ROSE
    #COLOR_LAVENDER
    #COLOR_TAN
    #COLOR_LIGHTBLUE
    #COLOR_AQUA
    #COLOR_LIME
    #COLOR_GOLD
    #COLOR_LIGHTORANGE
    #COLOR_ORANGE
    #COLOR_BLUEGRAY
    #COLOR_GRAY40
    #COLOR_DARKTEAL
    #COLOR_SEAGREEN
    #COLOR_DARKGREEN
    #COLOR_OLIVEGREEN
    #COLOR_BROWN
    #COLOR_PLUM
    #COLOR_INDIGO
    #COLOR_GRAY80
    #COLOR_DEFAULT_FOREGROUND = 64    
    #COLOR_DEFAULT_BACKGROUND = 65    
    #COLOR_TOOLTIP            = 81    
    #COLOR_AUTO               = 32767
EndEnumeration

Enumeration NumFormat
    #NUMFORMAT_GENERAL
    #NUMFORMAT_NUMBER
    #NUMFORMAT_NUMBER_D2
    #NUMFORMAT_NUMBER_SEP
    #NUMFORMAT_NUMBER_SEP_D2
    #NUMFORMAT_CURRENCY_NEGBRA
    #NUMFORMAT_CURRENCY_NEGBRARED
    #NUMFORMAT_CURRENCY_D2_NEGBRA
    #NUMFORMAT_CURRENCY_D2_NEGBRARED
    #NUMFORMAT_PERCENT
    #NUMFORMAT_PERCENT_D2
    #NUMFORMAT_SCIENTIFIC_D2
    #NUMFORMAT_FRACTION_ONEDIG
    #NUMFORMAT_FRACTION_TWODIG
    #NUMFORMAT_DATE
    #NUMFORMAT_CUSTOM_D_MON_YY
    #NUMFORMAT_CUSTOM_D_MON
    #NUMFORMAT_CUSTOM_MON_YY
    #NUMFORMAT_CUSTOM_HMM_AM
    #NUMFORMAT_CUSTOM_HMMSS_AM
    #NUMFORMAT_CUSTOM_HMM
    #NUMFORMAT_CUSTOM_HMMSS
    #NUMFORMAT_CUSTOM_MDYYYY_HMM
    #NUMFORMAT_NUMBER_SEP_NEGBRA = 37
    #NUMFORMAT_NUMBER_SEP_NEGBRARED
    #NUMFORMAT_NUMBER_D2_SEP_NEGBRA
    #NUMFORMAT_NUMBER_D2_SEP_NEGBRARED
    #NUMFORMAT_ACCOUNT
    #NUMFORMAT_ACCOUNTCUR
    #NUMFORMAT_ACCOUNT_D2
    #NUMFORMAT_ACCOUNT_D2_CUR
    #NUMFORMAT_CUSTOM_MMSS
    #NUMFORMAT_CUSTOM_H0MMSS
    #NUMFORMAT_CUSTOM_MMSS0
    #NUMFORMAT_CUSTOM_000P0E_PLUS0
    #NUMFORMAT_TEXT
EndEnumeration

Enumeration AlignH
    #ALIGNH_GENERAL
    #ALIGNH_LEFT
    #ALIGNH_CENTER
    #ALIGNH_RIGHT
    #ALIGNH_FILL
    #ALIGNH_JUSTIFY
    #ALIGNH_MERGE
    #ALIGNH_DISTRIBUTED
EndEnumeration

Enumeration AlignV
    #ALIGNV_TOP
    #ALIGNV_CENTER
    #ALIGNV_BOTTOM
    #ALIGNV_JUSTIFY
    #ALIGNV_DISTRIBUTED
EndEnumeration

Enumeration BorderStyle
    #BORDERSTYLE_NONE
    #BORDERSTYLE_THIN
    #BORDERSTYLE_MEDIUM
    #BORDERSTYLE_DASHED
    #BORDERSTYLE_DOTTED
    #BORDERSTYLE_THICK
    #BORDERSTYLE_DOUBLE
    #BORDERSTYLE_HAIR
    #BORDERSTYLE_MEDIUMDASHED
    #BORDERSTYLE_DASHDOT
    #BORDERSTYLE_MEDIUMDASHDOT
    #BORDERSTYLE_DASHDOTDOT
    #BORDERSTYLE_MEDIUMDASHDOTDOT
    #BORDERSTYLE_SLANTDASHDOT
EndEnumeration

Enumeration BorderDiagonal
    #BORDERDIAGONAL_NONE
    #BORDERDIAGONAL_DOWN
    #BORDERDIAGONAL_UP
    #BORDERDIAGONAL_BOTH
EndEnumeration

Enumeration FillPattern
    #FILLPATTERN_NONE
    #FILLPATTERN_SOLID
    #FILLPATTERN_GRAY50
    #FILLPATTERN_GRAY75
    #FILLPATTERN_GRAY25
    #FILLPATTERN_HORSTRIPE
    #FILLPATTERN_VERSTRIPE
    #FILLPATTERN_REVDIAGSTRIPE
    #FILLPATTERN_DIAGSTRIPE
    #FILLPATTERN_DIAGCROSSHATCH
    #FILLPATTERN_THICKDIAGCROSSHATCH
    #FILLPATTERN_THINHORSTRIPE
    #FILLPATTERN_THINVERSTRIPE
    #FILLPATTERN_THINREVDIAGSTRIPE
    #FILLPATTERN_THINDIAGSTRIPE
    #FILLPATTERN_THINHORCROSSHATCH
    #FILLPATTERN_THINDIAGCROSSHATCH
    #FILLPATTERN_GRAY12P5
    #FILLPATTERN_GRAY6P25
EndEnumeration

Enumeration Script
    #SCRIPT_NORMAL
    #SCRIPT_SUPER
    #SCRIPT_SUB
EndEnumeration

Enumeration Underline
    #UNDERLINE_NONE
    #UNDERLINE_SINGLE
    #UNDERLINE_DOUBLE
    #UNDERLINE_SINGLEACC = 33
    #UNDERLINE_DOUBLEACC = 34
EndEnumeration

Enumeration SheetType
    #SHEETTYPE_SHEET
    #SHEETTYPE_CHART
    #SHEETTYPE_UNKNOWN
EndEnumeration

Enumeration CellType
    #CELLTYPE_EMPTY
    #CELLTYPE_NUMBER
    #CELLTYPE_STRING
    #CELLTYPE_BOOLEAN
    #CELLTYPE_BLANK
    #CELLTYPE_ERROR
EndEnumeration

Enumeration ErrorType
    #ERRORTYPE_NULL    = 0
    #ERRORTYPE_DIV_0   = 7
    #ERRORTYPE_VALUE   = 15
    #ERRORTYPE_REF     = 23
    #ERRORTYPE_NAME    = 29
    #ERRORTYPE_NUM     = 36
    #ERRORTYPE_NA      = 42
    #ERRORTYPE_NOERROR = 255
EndEnumeration

Enumeration PictureType
    #PICTURETYPE_PNG
    #PICTURETYPE_JPEG
    #PICTURETYPE_WMF
    #PICTURETYPE_DIB
    #PICTURETYPE_EMF
    #PICTURETYPE_PICT
    #PICTURETYPE_TIFF
    #PICTURETYPE_ERROR = 255
EndEnumeration

Enumeration SheetState
    #SHEETSTATE_VISIBLE
    #SHEETSTATE_HIDDEN
    #SHEETSTATE_VERYHIDDEN
EndEnumeration

Enumeration Scope
    #SCOPE_UNDEFINED = -2
    #SCOPE_WORKBOOK  = -1
EndEnumeration

Enumeration Position
    #POSITION_MOVE_AND_SIZE
    #POSITION_ONLY_MOVE
    #POSITION_ABSOLUTE
EndEnumeration  

Enumeration PAPER
    #PAPER_DEFAULT
    #PAPER_LETTER
    #PAPER_LETTERSMALL
    #PAPER_TABLOID
    #PAPER_LEDGER
    #PAPER_LEGAL
    #PAPER_STATEMENT
    #PAPER_EXECUTIVE
    #PAPER_A3
    #PAPER_A4
    #PAPER_A4SMALL
    #PAPER_A5
    #PAPER_B4
    #PAPER_B5
    #PAPER_FOLIO
    #PAPER_QUATRO
    #PAPER_10x14
    #PAPER_10x17
    #PAPER_NOTE
    #PAPER_ENVELOPE_9
    #PAPER_ENVELOPE_10
    #PAPER_ENVELOPE_11
    #PAPER_ENVELOPE_12
    #PAPER_ENVELOPE_14
    #PAPER_C_SIZE
    #PAPER_D_SIZE
    #PAPER_E_SIZE
    #PAPER_ENVELOPE_DL
    #PAPER_ENVELOPE_C5
    #PAPER_ENVELOPE_C3
    #PAPER_ENVELOPE_C4
    #PAPER_ENVELOPE_C6
    #PAPER_ENVELOPE_C65
    #PAPER_ENVELOPE_B4
    #PAPER_ENVELOPE_B5
    #PAPER_ENVELOPE_B6
    #PAPER_ENVELOPE
    #PAPER_ENVELOPE_MONARCH
    #PAPER_US_ENVELOPE
    #PAPER_FANFOLD
    #PAPER_GERMAN_STD_FANFOLD
    #PAPER_GERMAN_LEGAL_FANFOLD
    #PAPER_B4_ISO
    #PAPER_JAPANESE_POSTCARD
    #PAPER_9x11
    #PAPER_10x11
    #PAPER_15x11
    #PAPER_ENVELOPE_INVITE
    #PAPER_US_LETTER_EXTRA = 50
    #PAPER_US_LEGAL_EXTRA
    #PAPER_US_TABLOID_EXTRA
    #PAPER_A4_EXTRA
    #PAPER_LETTER_TRANSVERSE
    #PAPER_A4_TRANSVERSE
    #PAPER_LETTER_EXTRA_TRANSVERSE
    #PAPER_SUPERA
    #PAPER_SUPERB
    #PAPER_US_LETTER_PLUS
    #PAPER_A4_PLUS
    #PAPER_A5_TRANSVERSE
    #PAPER_B5_TRANSVERSE
    #PAPER_A3_EXTRA
    #PAPER_A5_EXTRA
    #PAPER_B5_EXTRA
    #PAPER_A2
    #PAPER_A3_TRANSVERSE
    #PAPER_A3_EXTRA_TRANSVERSE
    #PAPER_JAPANESE_DOUBLE_POSTCARD
    #PAPER_A6
    #PAPER_JAPANESE_ENVELOPE_KAKU2
    #PAPER_JAPANESE_ENVELOPE_KAKU3
    #PAPER_JAPANESE_ENVELOPE_CHOU3
    #PAPER_JAPANESE_ENVELOPE_CHOU4
    #PAPER_LETTER_ROTATED
    #PAPER_A3_ROTATED
    #PAPER_A4_ROTATED
    #PAPER_A5_ROTATED
    #PAPER_B4_ROTATED
    #PAPER_B5_ROTATED
    #PAPER_JAPANESE_POSTCARD_ROTATED
    #PAPER_DOUBLE_JAPANESE_POSTCARD_ROTATED
    #PAPER_A6_ROTATED
    #PAPER_JAPANESE_ENVELOPE_KAKU2_ROTATED
    #PAPER_JAPANESE_ENVELOPE_KAKU3_ROTATED
    #PAPER_JAPANESE_ENVELOPE_CHOU3_ROTATED
    #PAPER_JAPANESE_ENVELOPE_CHOU4_ROTATED
    #PAPER_B6
    #PAPER_B6_ROTATED
    #PAPER_12x11
    #PAPER_JAPANESE_ENVELOPE_YOU4
    #PAPER_JAPANESE_ENVELOPE_YOU4_ROTATED
    #PAPER_PRC16K
    #PAPER_PRC32K
    #PAPER_PRC32K_BIG
    #PAPER_PRC_ENVELOPE1
    #PAPER_PRC_ENVELOPE2
    #PAPER_PRC_ENVELOPE3
    #PAPER_PRC_ENVELOPE4
    #PAPER_PRC_ENVELOPE5
    #PAPER_PRC_ENVELOPE6
    #PAPER_PRC_ENVELOPE7
    #PAPER_PRC_ENVELOPE8
    #PAPER_PRC_ENVELOPE9
    #PAPER_PRC_ENVELOPE10
    #PAPER_PRC16K_ROTATED
    #PAPER_PRC32K_ROTATED
    #PAPER_PRC32KBIG_ROTATED
    #PAPER_PRC_ENVELOPE1_ROTATED
    #PAPER_PRC_ENVELOPE2_ROTATED
    #PAPER_PRC_ENVELOPE3_ROTATED
    #PAPER_PRC_ENVELOPE4_ROTATED
    #PAPER_PRC_ENVELOPE5_ROTATED
    #PAPER_PRC_ENVELOPE6_ROTATED
    #PAPER_PRC_ENVELOPE7_ROTATED
    #PAPER_PRC_ENVELOPE8_ROTATED
    #PAPER_PRC_ENVELOPE9_ROTATED
    #PAPER_PRC_ENVELOPE10_ROTATED
EndEnumeration

Enumeration EnhancedProtection
    #PROT_DEFAULT = -1
    #PROT_ALL = 0
    #PROT_OBJECTS = 1
    #PROT_SCENARIOS = 2
    #PROT_FORMAT_CELLS = 4
    #PROT_FORMAT_COLUMNS = 8
    #PROT_FORMAT_ROWS = 16
    #PROT_INSERT_COLUMNS = 32
    #PROT_INSERT_ROWS = 64
    #PROT_INSERT_HYPERLINKS = 128
    #PROT_DELETE_COLUMNS = 256
    #PROT_DELETE_ROWS = 512
    #PROT_SEL_LOCKED_CELLS = 1024
    #PROT_SORT = 2048
    #PROT_AUTOFILTER = 4096
    #PROT_PIVOTTABLES = 8192
    #PROT_SEL_UNLOCKED_CELLS = 16384
EndEnumeration

Enumeration CFormatType
    #CFORMAT_BEGINWITH
    #CFORMAT_CONTAINSBLANKS
    #CFORMAT_CONTAINSERRORS
    #CFORMAT_CONTAINSTEXT
    #CFORMAT_DUPLICATEVALUES
    #CFORMAT_ENDSWITH
    #CFORMAT_EXPRESSION
    #CFORMAT_NOTCONTAINSBLANKS
    #CFORMAT_NOTCONTAINSERRORS
    #CFORMAT_NOTCONTAINSTEXT
    #CFORMAT_UNIQUEVALUES
EndEnumeration
  
Enumeration Operator
    #OPERATOR_EQUAL
    #OPERATOR_GREATER_THAN
    #OPERATOR_GREATER_THAN_OR_EQUAL
    #OPERATOR_LESS_THAN
    #OPERATOR_LESS_THAN_OR_EQUAL
    #OPERATOR_NOT_EQUAL
EndEnumeration

Enumeration Filter 
    #FILTER_VALUE
    #FILTER_TOP10
    #FILTER_CUSTOM
    #FILTER_DYNAMIC
    #FILTER_COLOR
    #FILTER_ICON
    #FILTER_EXT
    #FILTER_NOT_SET
EndEnumeration
  
ImportC "libxl.lib"   
  
  xlCreateBook.i() As "xlCreateBookW"
  xlCreateXMLBook.i() As "xlCreateXMLBookW"
  
  ;
  ; Book
  ;
  
  xlBookLoad.i(BookHandle.i, filename$) As "xlBookLoadW"
  xlBookSave.i(BookHandle.i, filename$) As "xlBookSaveW"
  
  xlBookLoadUsingTempFile.i(BookHandle.i, filename$, tempfile$) As "xlBookLoadUsingTempFileW"
  xlBookSaveUsingTempFile.i(BookHandle.i, filename$, useTempFile.i = 1) As "xlBookSaveUsingTempFileW"
  
  xlBookLoadPartially.i(BookHandle.i, filename$, sheetIndex.i, firstRow.i = -1, lastRow.i = -1, keepAllSheets.i = 0) As "xlBookLoadPartiallyW"
  xlBookLoadPartiallyUsingTempFile.i(BookHandle.i, filename$, sheetIndex.i, firstRow.i, lastRow.i, tempfile$, keepAllSheets.i = 0) As "xlBookLoadPartiallyUsingTempFileW"
  
  xlBookLoadWithoutEmptyCells.i(BookHandle.i, filename$) As "xlBookLoadWithoutEmptyCellsW"
  xlBookLoadInfo.i(BookHandle.i, filename$) As "xlBookLoadInfoW"
  xlBookLoadInfoRaw.i(BookHandle.i, buf, size.i) As "xlBookLoadInfoRawW"
  
  xlBookLoadRaw.i(BookHandle.i, buf, size.i) As "xlBookLoadRawW"
  xlBookLoadRawPartially.i(BookHandle.i, buf, size.i, sheetIndex.i, firstRow.i = -1, lastRow.i = -1, keepAllSheets.i = 0) As "xlBookLoadRawPartiallyW"
  xlBookSaveRaw.i(BookHandle.i, *buf, *size) As "xlBookSaveRawW"
  
  xlBookSetPassword(BookHandle.i, filename$) As "xlBookSetPasswordW"
  
  xlBookAddSheet.i(BookHandle.i, sheetname$, SheetHandle.i = 0) As "xlBookAddSheetW"  
  xlBookInsertSheet.i(BookHandle.i, sheetIndex.i, sheetname$, SheetHandle.i = 0) As "xlBookInsertSheetW"
  xlBookGetSheet.i(BookHandle.i, index.i) As "xlBookGetSheetW"
  xlBookGetSheetNameW.i(BookHandle.i, index.i)
  xlBookSheetType.i(BookHandle.i, index.i) As "xlBookSheetTypeW"
  xlBookMoveSheet.i(BookHandle.i, srcIndex.i, dstIndex.i) As "xlBookMoveSheetW"
  xlBookDelSheet.i(BookHandle.i, index.i) As "xlBookDelSheetW"
  xlBookSheetCount.i(BookHandle.i) As "xlBookSheetCountW"
  
  xlBookAddFormat.i(BookHandle.i, FormatHandle.i = 0) As "xlBookAddFormatW"
  xlBookAddFormatFromStyle.i(BookHandle.i, style.i) As "xlBookAddFormatFromStyleW"
  xlBookAddFont.i(BookHandle.i, initFontHandle.i = 0) As "xlBookAddFontW"
  xlBookAddRichString.i(BookHandle.i) As "xlBookAddRichStringW"
  xlBookAddCustomNumFormat(BookHandle.i, customNumFormat$) As "xlBookAddCustomNumFormatW"
  xlBookCustomNumFormatW.i(BookHandle.i, fmt.i)
  
  xlBookFormat.i(BookHandle.i, index.i) As "xlBookFormatW"
  xlBookFormatSize.i(BookHandle.i) As "xlBookFormatSizeW"
  
  xlBookFont.i(BookHandle.i, index.i) As "xlBookFontW"
  xlBookFontSize.i(BookHandle.i) As "xlBookFontSizeW"
  
  xlBookAddConditionalFormat.i(BookHandle.i) As "xlBookAddConditionalFormatW"
  xlBookConditionalFormat.i(BookHandle.i, index.i) As "xlBookConditionalFormatW"
  xlBookConditionalFormatSize.i(BookHandle.i) As "xlBookConditionalFormatSizeW"
  
  xlBookDatePack.d(BookHandle.i, year.i, month.i, day.i, hour.i = 0, min.i = 0, sec.i = 0, msec.i = 0) As "xlBookDatePackW"
  xlBookDateUnpack.i(BookHandle.i, value.d, *year, *month, *day, *hour = 0, *min = 0, *sec = 0, *msec = 0) As "xlBookDateUnpackW"
  
  xlBookColorPack.i(BookHandle.i, red.i, green.i, blue.i) As "xlBookColorPackW"
  xlBookColorUnpack(BookHandle.i, color.i, *red, *green, *blue) As "xlBookColorUnpackW"
  
  xlBookActiveSheet.i(BookHandle.i) As "xlBookActiveSheetW"
  xlBookSetActiveSheet(BookHandle.i, index.i) As "xlBookSetActiveSheetW"
  
  xlBookPictureSize.i(BookHandle.i) As "xlBookPictureSizeW"
  xlBookGetPicture.i(BookHandle.i, index.i, *buf, *size) As "xlBookGetPictureW"
  
  xlBookAddPicture.i(BookHandle.i, filename$) As "xlBookAddPictureW"
  xlBookAddPicture2.i(BookHandle.i, buf, size.i) As "xlBookAddPicture2W"
  xlBookAddPictureAsLink.i(BookHandle.i, filename$, insert.i = 0) As "xlBookAddPictureAsLinkW"
  
  xlBookDefaultFontW.i(BookHandle.i, *fontSize)
  xlBookSetDefaultFont(BookHandle.i, fontName$, fontSize.i) As "xlBookSetDefaultFontW"
  
  xlBookRefR1C1.i(BookHandle.i) As "xlBookRefR1C1W"
  xlBookSetRefR1C1(BookHandle.i, refR1C1.i) As "xlBookSetRefR1C1W"
  
  xlBookSetKey(BookHandle.i, name$, key$) As "xlBookSetKeyW"
  
  xlBookRgbMode.i(BookHandle.i) As "xlBookRgbModeW"
  xlBookSetRgbMode(BookHandle.i, rgbMode.i = 1) As "xlBookSetRgbModeW"
  
  xlBookCalcMode.i(BookHandle.i) As "xlBookCalcModeW"
  xlBookSetCalcMode(BookHandle.i, calcMode.i) As "xlBookSetCalcModeW"
  
  xlBookVersion.i(BookHandle.i) As "xlBookVersionW"
  xlBookBiffVersion.i(BookHandle.i) As "xlBookBiffVersionW"
  
  xlBookIsDate1904.i(BookHandle.i) As "xlBookIsDate1904W"
  xlBookSetDate1904(BookHandle.i, date1904.i = 1) As "xlBookSetDate1904W"
  
  xlBookIsTemplate.i(BookHandle.i) As "xlBookIsTemplateW"
  xlBookSetTemplate(BookHandle.i, tmpl.i = 1) As "xlBookSetTemplateW"
  
  xlBookIsWriteProtected.i(BookHandle.i) As "xlBookIsWriteProtectedW"
  
  xlBookCoreProperties.i(BookHandle.i) As "xlBookCorePropertiesW"
  
  xlBookRemoveVBA.i(BookHandle.i) As "xlBookRemoveVBAW"
  xlBookRemovePrinterSettings.i(BookHandle.i) As "xlBookRemovePrinterSettingsW"
  xlBookRemoveAllPhonetics(BookHandle.i) As "xlBookRemoveAllPhoneticsW"
  
  xlBookDpiAwareness.i(BookHandle.i) As "xlBookDpiAwarenessW"
  xlBookSetDpiAwareness(BookHandle.i, dpiAwareness.i) As "xlBookSetDpiAwarenessW"
  
  xlBookClear(BookHandle.i) As "xlBookClearW"
    
  xlBookErrorMessageW.i(BookHandle.i)
  xlBookErrorCode.i(BookHandle.i) As "xlBookErrorCodeW"
  
  xlBookRelease(BookHandle.i) As "xlBookReleaseW" 
  
  ;
  ; Sheet
  ;
  
  xlSheetCellType.i(SheetHandle.i, row.i, col.i) As "xlSheetCellTypeW"
  xlSheetIsFormula.i(SheetHandle.i, row.i, col.i) As "xlSheetIsFormulaW"
  
  xlSheetCellFormatW.i(SheetHandle.i, row.i, col.i) As "xlSheetCellFormatW"
  xlSheetSetCellFormat(SheetHandle.i, row.i, col.i, FormatHandle.i) As "xlSheetSetCellFormatW"
  
  xlSheetReadStrW(SheetHandle.i, row.i, col.i, *FormatHandle = 0) 
  xlSheetWriteStr.i(SheetHandle.i, row.i, col.i, value$, FormatHandle.i = 0) As "xlSheetWriteStrW"
  xlSheetWriteStrAsNum.i(SheetHandle.i, row.i, col.i, value$, FormatHandle.i = 0) As "xlSheetWriteStrAsNumW"
  
  xlSheetReadRichStr.i(SheetHandle.i, row.i, col.i, *FormatHandle = 0) As "xlSheetReadRichStrW"
  xlSheetWriteRichStr.i(SheetHandle.i, row.i, col.i, richStringHandle.i, FormatHandle.i = 0) As "xlSheetWriteRichStrW"
  
  xlSheetReadNum.d(SheetHandle.i, row.i, col.i, *FormatHandle = 0) As "xlSheetReadNumW"
  xlSheetWriteNum.i(SheetHandle.i, row.i, col.i, value.d, FormatHandle.i = 0) As "xlSheetWriteNumW"
  
  xlSheetReadBool.i(SheetHandle.i, row.i, col.i, *FormatHandle = 0) As "xlSheetReadBoolW"
  xlSheetWriteBool.i(SheetHandle.i, row.i, col.i, value.i, FormatHandle.i = 0) As "xlSheetWriteBoolW"
  
  xlSheetReadBlank.i(SheetHandle.i, row.i, col.i, *FormatHandle = 0) As "xlSheetReadBlankW"
  xlSheetWriteBlank.i(SheetHandle.i, row.i, col.i, FormatHandle.i) As "xlSheetWriteBlankW"
  
  xlSheetReadFormulaW.i(SheetHandle.i, row.i, col.i, *FormatHandle = 0)
  xlSheetWriteFormula.i(SheetHandle.i, row.i, col.i, value$, FormatHandle.i = 0) As "xlSheetWriteFormulaW"
  
  xlSheetWriteFormulaNum.i(SheetHandle.i, row.i, col.i, expr$, value.d, FormatHandle.i = 0) As "xlSheetWriteFormulaNumW"
  xlSheetWriteFormulaStr.i(SheetHandle.i, row.i, col.i, expr$, value$, FormatHandle.i = 0) As "xlSheetWriteFormulaStrW"
  xlSheetWriteFormulaBool.i(SheetHandle.i, row.i, col.i, expr$, value.i, FormatHandle.i = 0) As "xlSheetWriteFormulaBoolW"
  
  xlSheetReadCommentW.i(SheetHandle.i, row.i, col.i)
  xlSheetWriteComment(SheetHandle.i, row.i, col.i, value$, author$ = "", width.i = 129, height.i = 75) As "xlSheetWriteCommentW"
  xlSheetRemoveComment(SheetHandle.i, row.i, col.i) As "xlSheetRemoveCommentW"
  
  xlSheetIsDate.i(SheetHandle.i, row.i, col.i) As "xlSheetIsDateW"
  xlSheetIsRichStr.i(SheetHandle.i, row.i, col.i) As "xlSheetIsRichStrW"
  
  xlSheetReadError.i(SheetHandle.i, row.i, col.i) As "xlSheetReadErrorW"
  xlSheetWriteError(SheetHandle.i, row.i, col.i, error.i, FormatHandle.i = 0) As "xlSheetWriteErrorW"
  
  xlSheetColWidth.d(SheetHandle.i, col.i) As "xlSheetColWidthW"
  xlSheetRowHeight.d(SheetHandle.i, row.i) As "xlSheetRowHeightW"
  
  xlSheetColWidthPx.i(SheetHandle.i, col.i) As "xlSheetColWidthPxW"
  xlSheetRowHeightPx.i(SheetHandle.i, row.i) As "xlSheetRowHeightPxW"
  
  xlSheetColFormat.i(SheetHandle.i, col.i) As "xlSheetColFormatW"
  xlSheetRowFormat.i(SheetHandle.i, row.i) As "xlSheetRowFormatW"
  
  xlSheetSetCol.i(SheetHandle.i, colFirst.i, colLast.i, width.d, FormatHandle.i = 0, hidden.i = 0) As "xlSheetSetColW"
  xlSheetSetColPx.i(SheetHandle.i, colFirst.i, colLast.i, widthPx.d, FormatHandle.i = 0, hidden.i = 0) As "xlSheetSetColPxW"
  
  xlSheetSetRow.i(SheetHandle.i, row.i, height.d, FormatHandle.i = 0, hidden.i = 0) As "xlSheetSetRowW"
  xlSheetSetRowPx.i(SheetHandle.i, row.i, heightPx.d, FormatHandle.i = 0, hidden.i = 0) As "xlSheetSetRowPxW"
  
  xlSheetRowHidden.i(SheetHandle.i, row.i) As "xlSheetRowHiddenW"
  xlSheetSetRowHidden.i(SheetHandle.i, row.i, hidden.i) As "xlSheetSetRowHiddenW"
  
  xlSheetColHidden.i(SheetHandle.i, col.i) As "xlSheetColHiddenW"
  xlSheetSetColHidden.i(SheetHandle.i, col.i, hidden.i) As "xlSheetSetColHiddenW"
  
  xlSheetDefaultRowHeight.d(SheetHandle.i) As "xlSheetDefaultRowHeightW"
  xlSheetSetDefaultRowHeight(SheetHandle.i, height.d) As "xlSheetSetDefaultRowHeightW"
  
  xlSheetGetMerge.i(SheetHandle.i, row.i, col.i, *rowFirst, *rowLast, *colFirst, *colLast) As "xlSheetGetMergeW"
  xlSheetSetMerge.i(SheetHandle.i, rowFirst.i, rowLast.i, colFirst.i, colLast.i) As "xlSheetSetMergeW"
  xlSheetDelMerge.i(SheetHandle.i, row.i, col.i) As "xlSheetDelMergeW"
  
  xlSheetMergeSize.i(SheetHandle.i) As "xlSheetMergeSizeW"
  xlSheetMerge.i(SheetHandle.i, index.i, *rowFirst, *rowLast, *colFirst, *colLast) As "xlSheetMergeW"
  xlSheetDelMergeByIndex.i(SheetHandle.i, index.i) As "xlSheetDelMergeByIndexW"
  
  xlSheetPictureSize.i(SheetHandle.i) As "xlSheetPictureSizeW"
  xlSheetGetPicture.i(SheetHandle.i, index.i, *rowTop = 0, *colLeft = 0, *rowBottom = 0, *colRight = 0, *width = 0, *height = 0, *offset_x = 0, *offset_y = 0, *linkPath = 0) As "xlSheetGetPictureW"
  
  xlSheetRemovePictureByIndex.i(SheetHandle.i, index.i) As "xlSheetRemovePictureByIndexW"
  
  xlSheetSetPicture(SheetHandle.i, row.i, col.i, pictureId.i, scale.d = 1, offset_x = 0, offset_y = 0, pos = #POSITION_MOVE_AND_SIZE) As "xlSheetSetPictureW"
  xlSheetSetPicture2(SheetHandle.i, row, col, pictureId, width = -1, height = -1, offset_x = 0, offset_y = 0, pos = #POSITION_MOVE_AND_SIZE) As "xlSheetSetPicture2W"
  xlSheetRemovePicture.i(SheetHandle.i, row, col) As "xlSheetRemovePictureW"
  
  xlSheetGetHorPageBreak.i(SheetHandle, index) As "xlSheetGetHorPageBreakW"
  xlSheetGetHorPageBreakSize.i(SheetHandle) As "xlSheetGetHorPageBreakSizeW"
  
  xlSheetGetVerPageBreak.i(SheetHandle, index) As "xlSheetGetVerPageBreakW"
  xlSheetGetVerPageBreakSize.i(SheetHandle) As "xlSheetGetVerPageBreakSizeW"
  
  xlSheetSetHorPageBreak.i(SheetHandle, row, pageBreak = 1) As "xlSheetSetHorPageBreakW"
  xlSheetSetVerPageBreak.i(SheetHandle, col, pageBreak = 1) As "xlSheetSetVerPageBreakW"
  
  xlSheetSplit(SheetHandle, row, col) As "xlSheetSplitW"
  xlSheetSplitInfo.i(SheetHandle, *row, *col) As "xlSheetSplitInfoW"
  
  xlSheetGroupRows.i(SheetHandle, rowFirst, rowLast, collapsed) As "xlSheetGroupRowsW"
  xlSheetGroupCols.i(SheetHandle, colFirst, colLast, collapsed) As "xlSheetGroupColsW"
  
  xlSheetGroupSummaryBelow.i(SheetHandle) As "xlSheetGroupSummaryBelowW"
  xlSheetSetGroupSummaryBelow(SheetHandle, below) As "xlSheetSetGroupSummaryBelowW"
  
  xlSheetGroupSummaryRight.i(SheetHandle) As "xlSheetGroupSummaryRightW"
  xlSheetSetGroupSummaryRight(SheetHandle, right) As "xlSheetSetGroupSummaryRightW"
  
  xlSheetClear.i(SheetHandle, rowFirst, rowLast, colFirst, colLast) As "xlSheetClearW"
  
  xlSheetInsertCol.i(SheetHandle, colFirst, colLast) As "xlSheetInsertColW"
  xlSheetInsertRow.i(SheetHandle, rowFirst, rowLast) As "xlSheetInsertRowW"
  xlSheetRemoveCol.i(SheetHandle, colFirst, colLast) As "xlSheetRemoveColW"
  xlSheetRemoveRow.i(SheetHandle, rowFirst, rowLast) As "xlSheetRemoveRowW"
  
  xlSheetInsertColAndKeepRanges.i(SheetHandle, colFirst, colLast) As "xlSheetInsertColAndKeepRangesW"
  xlSheetInsertRowAndKeepRanges.i(SheetHandle, rowFirst, rowLast) As "xlSheetInsertRowAndKeepRangesW"
  xlSheetRemoveColAndKeepRanges.i(SheetHandle, colFirst, colLast) As "xlSheetRemoveColAndKeepRangesW"
  xlSheetRemoveRowAndKeepRanges.i(SheetHandle, rowFirst, rowLast) As "xlSheetRemoveRowAndKeepRangesW"
  
  xlSheetCopyCell.i(SheetHandle, rowSrc, colSrc, rowDst, colDst) As "xlSheetCopyCellW"
  
  xlSheetFirstRow.i(SheetHandle) As "xlSheetFirstRowW"
  xlSheetLastRow.i(SheetHandle) As "xlSheetLastRowW"
  xlSheetFirstCol.i(SheetHandle) As "xlSheetFirstColW"
  xlSheetLastCol.i(SheetHandle) As "xlSheetLastColW"
  
  xlSheetFirstFilledRow.i(SheetHandle) As "xlSheetFirstFilledRowW"
  xlSheetLastFilledRow.i(SheetHandle) As "xlSheetLastFilledRowW"
  xlSheetFirstFilledCol.i(SheetHandle) As "xlSheetFirstFilledColW"
  xlSheetLastFilledCol.i(SheetHandle) As "xlSheetLastFilledColW"
  
  xlSheetDisplayGridlines.i(SheetHandle) As "xlSheetDisplayGridlinesW"
  xlSheetSetDisplayGridlines(SheetHandle, show) As "xlSheetSetDisplayGridlinesW"
  
  xlSheetPrintGridlines.i(SheetHandle) As "xlSheetPrintGridlinesW"
  xlSheetSetPrintGridlines(SheetHandle, print) As "xlSheetSetPrintGridlinesW"
  
  xlSheetZoom.i(SheetHandle) As "xlSheetZoomW"
  xlSheetSetZoom(SheetHandle, zoom) As "xlSheetSetZoomW"
  
  xlSheetPrintZoom.i(SheetHandle) As "xlSheetPrintZoomW"
  xlSheetSetPrintZoom(SheetHandle, zoom) As "xlSheetSetPrintZoomW"
  
  xlSheetGetPrintFit.i(SheetHandle, *wPages, *hPages) As "xlSheetGetPrintFitW"
  xlSheetSetPrintFit(SheetHandle, wPages, hPages) As "xlSheetSetPrintFitW"
  
  xlSheetLandscape.i(SheetHandle) As "xlSheetLandscapeW"
  xlSheetSetLandscape(SheetHandle, landscape) As "xlSheetSetLandscapeW"
  
  xlSheetPaper.i(SheetHandle) As "xlSheetPaperW"
  xlSheetSetPaper(SheetHandle, paper) As "xlSheetSetPaperW"
  
  xlSheetHeaderW.i(SheetHandle)
  xlSheetSetHeader.i(SheetHandle, header$, margin.d) As "xlSheetSetHeaderW"
  xlSheetHeaderMargin.d(SheetHandle) As "xlSheetHeaderMarginW"
  
  xlSheetFooterW.i(SheetHandle)
  xlSheetSetFooter.i(SheetHandle, footer$, margin.d) As "xlSheetSetFooterW"
  xlSheetFooterMargin.d(SheetHandle) As "xlSheetFooterMarginW"
  
  xlSheetHCenter.i(SheetHandle) As "xlSheetHCenterW"
  xlSheetSetHCenter(SheetHandle, hCenter) As "xlSheetSetHCenterW"
  
  xlSheetVCenter.i(SheetHandle) As "xlSheetVCenterW"
  xlSheetSetVCenter(SheetHandle, vCenter) As "xlSheetSetVCenterW"
  
  xlSheetMarginLeft.i(SheetHandle) As "xlSheetMarginLeftW"
  xlSheetSetMarginLeft(SheetHandle, margin.d) As "xlSheetSetMarginLeftW"
  
  xlSheetMarginRight.i(SheetHandle) As "xlSheetMarginRightW"
  xlSheetSetMarginRight(SheetHandle, margin.d) As "xlSheetSetMarginRightW"
  
  xlSheetMarginTop.i(SheetHandle) As "xlSheetMarginTopW"
  xlSheetSetMarginTop(SheetHandle, margin.d) As "xlSheetSetMarginTopW"
  
  xlSheetMarginBottom.i(SheetHandle) As "xlSheetMarginBottomW"
  xlSheetSetMarginBottom(SheetHandle, margin.d) As "xlSheetSetMarginBottomW"
  
  xlSheetPrintRowCol.i(SheetHandle) As "xlSheetPrintRowColW"
  xlSheetSetPrintRowCol(SheetHandle, print) As "xlSheetSetPrintRowColW"
  
  xlSheetPrintRepeatRows.i(SheetHandle, *rowFirst, *rowLast) As "xlSheetPrintRepeatRowsW"
  xlSheetSetPrintRepeatRows(SheetHandle, rowFirst, rowLast) As "xlSheetSetPrintRepeatRowsW"
  
  xlSheetPrintRepeatCols.i(SheetHandle, *colFirst, *colLast) As "xlSheetPrintRepeatColsW"
  xlSheetSetPrintRepeatCols(SheetHandle, colFirst, colLast) As "xlSheetSetPrintRepeatColsW"
  
  xlSheetPrintArea.i(SheetHandle, *rowFirst, *rowLast, *colFirst, *colLast) As "xlSheetPrintAreaW"
  xlSheetSetPrintArea(SheetHandle, rowFirst, rowLast, colFirst, colLast) As "xlSheetSetPrintAreaW"
  
  xlSheetClearPrintRepeats(SheetHandle) As "xlSheetClearPrintRepeatsW"
  xlSheetClearPrintArea(SheetHandle) As "xlSheetClearPrintAreaW"
  
  xlSheetGetNamedRange.i(SheetHandle, name$, *rowFirst, *rowLast, *colFirst, *colLast, scopeId, *hidden) As "xlSheetGetNamedRangeW"
  xlSheetSetNamedRange.i(SheetHandle, name$, rowFirst, rowLast, colFirst, colLast, scopeId) As "xlSheetSetNamedRangeW"
  xlSheetDelNamedRange.i(SheetHandle, name$, scopeId) As "xlSheetDelNamedRangeW"
  
  xlSheetNamedRangeSize.i(SheetHandle) As "xlSheetNamedRangeSizeW"
  xlSheetNamedRangeW.i(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *scopeId, *hidden)
  
  xlSheetGetTable.i(SheetHandle, name$, *rowFirst, *rowLast, *colFirst, *colLast, *headerRowCount, *totalsRowCount) As "xlSheetGetTableW"
  xlSheetTableSize.i(SheetHandle) As "xlSheetTableSizeW"
  xlSheetTableW.i(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *headerRowCount, *totalsRowCount)
  
  xlSheetAddTable.i(SheetHandle, name$, rowFirst, rowLast, colFirst, colLast, hasHeaders, tableStyle) As "xlSheetAddTableW"
  xlSheetGetTableByName.i(SheetHandle, name$) As "xlSheetGetTableByNameW"
  xlSheetGetTableByIndex.i(SheetHandle, index) As "xlSheetGetTableByIndexW"
  
  xlSheetHyperlinkSize.i(SheetHandle) As "xlSheetHyperlinkSizeW"
  xlSheetHyperlinkW.i(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast)
  xlSheetDelHyperlink.i(SheetHandle, index) As "xlSheetDelHyperlinkW"
  xlSheetAddHyperlink(SheetHandle, hyperlink$, rowFirst, rowLast, colFirst, colLast) As "xlSheetAddHyperlinkW"
  xlSheetHyperlinkIndex.i(SheetHandle, row, col) As "xlSheetHyperlinkIndexW"
  
  xlSheetIsAutoFilter.i(SheetHandle) As "xlSheetIsAutoFilterW"
  xlSheetAutoFilter.i(SheetHandle) As "xlSheetAutoFilterW"
  xlSheetApplyFilter(SheetHandle) As "xlSheetApplyFilterW"
  xlSheetApplyFilter2(SheetHandle, AutoFilterHandle) As "xlSheetApplyFilter2W"
  xlSheetRemoveFilter(SheetHandle) As "xlSheetRemoveFilterW"
  
  xlSheetNameW.i(SheetHandle)
  xlSheetSetName(SheetHandle, name$) As "xlSheetSetNameW"
  
  xlSheetProtect.i(SheetHandle) As "xlSheetProtectW"
  xlSheetSetProtect(SheetHandle, protect) As "xlSheetSetProtectW"
  xlSheetSetProtectEx(SheetHandle, protect, password$, enhancedProtection) As "xlSheetSetProtectExW"
  
  xlSheetHidden.i(SheetHandle) As "xlSheetHiddenW"
  xlSheetSetHidden.i(SheetHandle, hidden) As "xlSheetSetHiddenW"
  
  xlSheetGetTopLeftView(SheetHandle, *row, *col) As "xlSheetGetTopLeftViewW"
  xlSheetSetTopLeftView(SheetHandle, row, col) As "xlSheetSetTopLeftViewW"
  
  xlSheetRightToLeft.i(SheetHandle) As "xlSheetRightToLeftW"
  xlSheetSetRightToLeft(SheetHandle, rightToLeft) As "xlSheetSetRightToLeftW"
  
  xlSheetSetAutoFitArea(SheetHandle, rowFirst, rowLast, colFirst, colLast) As "xlSheetSetAutoFitAreaW"
  
  xlSheetAddrToRowCol(SheetHandle, addr$, *row, *col, *rowRelative, *colRelative) As "xlSheetAddrToRowColW"
  xlSheetRowColToAddrW.i(SheetHandle, row, col, rowRelative, colRelative)
  
  xlSheetTabColor.i(SheetHandle) As "xlSheetTabColorW"
  xlSheetSetTabColor(SheetHandle, color) As "xlSheetSetTabColorW"
  
  xlSheetGetTabRgbColor.i(SheetHandle, *red, *green, *blue) As "xlSheetGetTabRgbColorW"
  xlSheetSetTabRgbColor(SheetHandle, red, green, blue) As "xlSheetSetTabRgbColorW"
  
  xlSheetSetBorder.i(SheetHandle, rowFirst, rowLast, colFirst, colLast, borderStyle, borderColor) As "xlSheetSetBorderW"
  
  xlSheetAddIgnoredError.i(SheetHandle, rowFirst, rowLast, colFirst, colLast, iError) As "xlSheetAddIgnoredErrorW"
  
  xlSheetAddDataValidation(SheetHandle, type, op, rowFirst, rowLast, colFirst, colLast, value1$, value2$) As "xlSheetAddDataValidationW"
  
  xlSheetAddDataValidationEx(SheetHandle, type, op, rowFirst, rowLast, colFirst, colLast, value1$, value2$, 
                             allowBlank, hideDropDown, showInputMessage, showErrorMessage, promptTitle$, prompt$,
                             errorTitle$, error$, errorStyle) As "xlSheetAddDataValidationExW"
  
  xlSheetAddDataValidationDouble(SheetHandle, type, op, rowFirst, rowLast, colFirst, colLast, value1.d, value2.d) As "xlSheetAddDataValidationDoubleW"
  
  xlSheetAddDataValidationDoubleEx(SheetHandle, type, op, rowFirst, rowLast, colFirst, colLast, value1.d, value2.d, 
                                   allowBlank, hideDropDown, showInputMessage, showErrorMessage, promptTitle$, prompt$,
                                   errorTitle$, error$, errorStyle) As "xlSheetAddDataValidationDoubleExW"
  
  xlSheetRemoveDataValidations(SheetHandle) As "xlSheetRemoveDataValidationsW"
  
  xlSheetFormControlSize.i(SheetHandle) As "xlSheetFormControlSizeW"  
  xlSheetFormControl.i(SheetHandle, index) As "xlSheetFormControlW"
  
  xlSheetAddConditionalFormatting.i(SheetHandle, rowFirst, rowLast, colFirst, colLast) As "xlSheetAddConditionalFormattingW"
  xlSheetConditionalFormatting.i(SheetHandle, index) As "xlSheetConditionalFormattingW"
  xlSheetRemoveConditionalFormatting.i(SheetHandle, index) As "xlSheetRemoveConditionalFormattingW"
  xlSheetConditionalFormattingSize.i(SheetHandle) As "xlSheetConditionalFormattingSizeW"
  
  xlSheetGetActiveCell.i(SheetHandle, *row, *col) As "xlSheetGetActiveCellW"
  xlSheetSetActiveCell(SheetHandle, row, col) As "xlSheetSetActiveCellW"
  
  xlSheetSelectionRangeW.i(SheetHandle)
  xlSheetAddSelectionRange(SheetHandle, sqref$) As "xlSheetAddSelectionRangeW"
  xlSheetRemoveSelection(SheetHandle) As "xlSheetRemoveSelectionW"
    
  ;
  ; Format
  ;
  
  xlFormatFont.i(FormatHandle.i) As "xlFormatFontW"
  xlFormatSetFont.i(FormatHandle.i, FontHandle.i) As "xlFormatSetFontW"
  
  xlFormatNumFormat.i(FormatHandle.i) As "xlFormatNumFormatW"
  xlFormatSetNumFormat(FormatHandle.i, numFormat.i) As "xlFormatSetNumFormatW"
  
  xlFormatAlignHW.i(FormatHandle.i) As "xlFormatAlignHW"
  xlFormatSetAlignHW(FormatHandle.i, align.i) As "xlFormatSetAlignHW"
    
  xlFormatAlignVW.i(FormatHandle.i) As "xlFormatAlignVW"
  xlFormatSetAlignVW(FormatHandle.i, align.i) As "xlFormatSetAlignVW"
  
  xlFormatWrap.i(FormatHandle.i) As "xlFormatWrapW"
  xlFormatSetWrap(FormatHandle.i, wrap.i) As "xlFormatSetWrapW"
    
  xlFormatRotation.i(FormatHandle.i) As "xlFormatRotationW"
  xlFormatSetRotation(FormatHandle.i, rotation.i) As "xlFormatSetRotationW"
  
  xlFormatIndent.i(FormatHandle.i) As "xlFormatIndentW"
  xlFormatSetIndent(FormatHandle.i, indent.i) As "xlFormatSetIndentW"
    
  xlFormatShrinkToFit.i(FormatHandle.i) As "xlFormatShrinkToFitW"
  xlFormatSetShrinkToFit(FormatHandle.i, shrinkToFit.i) As "xlFormatSetShrinkToFitW"
  
  xlFormatSetBorder.i(FormatHandle.i, style.i = #BORDERSTYLE_THIN) As "xlFormatSetBorderW"
  xlFormatSetBorderColor(FormatHandle.i, color.i) As "xlFormatSetBorderColorW"
  
  xlFormatBorderLeft.i(FormatHandle.i) As "xlFormatBorderLeftW"
  xlFormatSetBorderLeft(FormatHandle.i, style.i) As "xlFormatSetBorderLeftW"
  
  xlFormatBorderRight.i(FormatHandle.i) As "xlFormatBorderRightW"
  xlFormatSetBorderRight(FormatHandle.i, style.i) As "xlFormatSetBorderRightW"
    
  xlFormatBorderTop.i(FormatHandle.i) As "xlFormatBorderTopW"
  xlFormatSetBorderTop(FormatHandle.i, style.i) As "xlFormatSetBorderTopW"
      
  xlFormatBorderBottom.i(FormatHandle.i) As "xlFormatBorderBottomW"  
  xlFormatSetBorderBottom(FormatHandle.i, style.i) As "xlFormatSetBorderBottomW"
    
  xlFormatBorderLeftColor.i(FormatHandle.i) As "xlFormatBorderLeftColorW"
  xlFormatSetBorderLeftColor(FormatHandle.i, color.i) As "xlFormatSetBorderLeftColorW"
    
  xlFormatBorderRightColor.i(FormatHandle.i) As "xlFormatBorderRightColorW"
  xlFormatSetBorderRightColor(FormatHandle.i, color.i) As "xlFormatSetBorderRightColorW"
      
  xlFormatBorderTopColor.i(FormatHandle.i) As "xlFormatBorderTopColorW"
  xlFormatSetBorderTopColor(FormatHandle.i, color.i) As "xlFormatSetBorderTopColorW"
       
  xlFormatBorderBottomColor.i(FormatHandle.i) As "xlFormatBorderBottomColorW"
  xlFormatSetBorderBottomColor(FormatHandle.i, color.i) As "xlFormatSetBorderBottomColorW"
                    
  xlFormatBorderDiagonal.i(FormatHandle.i) As "xlFormatBorderDiagonalW"
  xlFormatSetBorderDiagonal(FormatHandle.i, border.i) As "xlFormatSetBorderDiagonalW"
    
  xlFormatBorderDiagonalStyle.i(FormatHandle.i) As "xlFormatBorderDiagonalStyleW"
  xlFormatSetBorderDiagonalStyle(FormatHandle.i, style.i) As "xlFormatSetBorderDiagonalStyleW"
    
  xlFormatBorderDiagonalColor.i(FormatHandle.i) As "xlFormatBorderDiagonalColorW"
  xlFormatSetBorderDiagonalColor(FormatHandle.i, color.i) As "xlFormatSetBorderDiagonalColorW"
    
  xlFormatFillPattern.i(FormatHandle.i) As "xlFormatFillPatternW"
  xlFormatSetFillPattern(FormatHandle.i, pattern.i) As "xlFormatSetFillPatternW"
    
  xlFormatPatternForegroundColor.i(FormatHandle.i) As "xlFormatPatternForegroundColorW"
  xlFormatSetPatternForegroundColor(FormatHandle.i, color.i) As "xlFormatSetPatternForegroundColorW"
    
  xlFormatPatternBackgroundColor.i(FormatHandle.i) As "xlFormatPatternBackgroundColorW"
  xlFormatSetPatternBackgroundColor(FormatHandle.i, color.i) As "xlFormatSetPatternBackgroundColorW"
    
  xlFormatLocked.i(FormatHandle.i) As "xlFormatLockedW"
  xlFormatSetLocked(FormatHandle.i, locked.i) As "xlFormatSetLockedW"
    
  xlFormatHidden.i(FormatHandle.i) As "xlFormatHiddenW"
  xlFormatSetHidden(FormatHandle.i, hidden.i) As "xlFormatSetHiddenW"
  
  ;
  ; Font
  ;
  
  xlFontSize.i(FontHandle.i) As "xlFontSizeW"
  xlFontSetSize(FontHandle.i, size.i) As "xlFontSetSizeW"
  
  xlFontItalic.i(FontHandle.i) As "xlFontItalicW"
  xlFontSetItalic(FontHandle.i, italic.i = 1) As "xlFontSetItalicW"
    
  xlFontStrikeOut.i(FontHandle.i) As "xlFontStrikeOutW"
  xlFontSetStrikeOut(FontHandle.i, strikeOut.i = 1) As "xlFontSetStrikeOutW"
  
  ; use Color enumeration here
  xlFontColor.i(FontHandle.i) As "xlFontColorW"
  xlFontSetColor(FontHandle.i, color.i) As "xlFontSetColorW"
  
  xlFontBold.i(FontHandle.i) As "xlFontBoldW"
  xlFontSetBold(FontHandle.i, bold.i = 1) As "xlFontSetBoldW"
  
  ; use Script enumeration here
  xlFontScript.i(FontHandle.i) As "xlFontScriptW"
  xlFontSetScript(FontHandle.i, script.i) As "xlFontSetScriptW" 
  
  ; use Underline enumeration here
  xlFontUnderline.i(FontHandle.i) As "xlFontUnderlineW"
  xlFontSetUnderline(FontHandle.i, underline.i = #UNDERLINE_SINGLE) As "xlFontSetUnderlineW"
  
  xlFontNameW.i(FontHandle.i)
  xlFontSetName(FontHandle.i, fontName$) As "xlFontSetNameW"
  
  ;
  ; AutoFilter
  ;
  
  xlAutoFilterGetRef.i(AutoFilterHandle.i, *rowFirst, *rowLast, *colFirst, *colLast) As "xlAutoFilterGetRefW"
  xlAutoFilterSetRef(AutoFilterHandle.i, rowFirst, rowLast, colFirst, colLast) As "xlAutoFilterSetRefW"
  
  xlAutoFilterColumn.i(AutoFilterHandle.i, colId) As "xlAutoFilterColumnW"
  
  xlAutoFilterColumnSize.i(AutoFilterHandle.i) As "xlAutoFilterColumnSizeW"
  xlAutoFilterColumnByIndex.i(AutoFilterHandle.i, index) As "xlAutoFilterColumnByIndexW"
  
  xlAutoFilterGetSortRange.i(AutoFilterHandle.i, *rowFirst, *rowLast, *colFirst, *colLast) As "xlAutoFilterGetSortRangeW"
  
  xlAutoFilterGetSort.i(AutoFilterHandle.i, *columnIndex, *descending) As "xlAutoFilterGetSortW"
  xlAutoFilterSetSort.i(AutoFilterHandle.i, columnIndex, descending = 0) As "xlAutoFilterSetSortW"
  xlAutoFilterAddSort.i(AutoFilterHandle.i, columnIndex, descending = 0) As "xlAutoFilterAddSortW"
  
  ;
  ; FilterColumn
  ;
  
  xlFilterColumnIndex.i(FilterColumnHandle.i) As "xlFilterColumnIndexW"
  
  ; use Filter enumeration here
  xlFilterColumnFilterType.i(FilterColumnHandle.i) As "xlFilterColumnFilterTypeW"
  
  xlFilterColumnFilterSize.i(FilterColumnHandle.i) As "xlFilterColumnFilterSizeW"
  xlFilterColumnFilterW(FilterColumnHandle.i, index)
  xlFilterColumnAddFilter(FilterColumnHandle.i, value$) As "xlFilterColumnAddFilterW"
  
  xlFilterColumnGetTop10.i(FilterColumnHandle.i, *value, *top, *percent) As "xlFilterColumnGetTop10W"
  xlFilterColumnSetTop10(FilterColumnHandle.i, value.d, top = 1, percent = 0) As "xlFilterColumnSetTop10W"
  
  ; use Operator enumeration here
  xlFilterColumnGetCustomFilterW.i(FilterColumnHandle.i, *op1, *v1, *op2, *v2, *andOp)
  xlFilterColumnSetCustomFilter(FilterColumnHandle.i, op, val$) As "xlFilterColumnSetCustomFilterW"
  xlFilterColumnSetCustomFilterEx(FilterColumnHandle.i, op1, v1$, op2, v2$, andOp) As "xlFilterColumnSetCustomFilterExW"
  
  xlFilterColumnClear(FilterColumnHandle.i) As "xlFilterColumnClearW"
  
  ;
  ; RichString 
  ;
  
  xlRichStringAddFont.i(RichStringHandle.i, FontHandle.i = 0) As "xlRichStringAddFontW"
  xlRichStringAddText(RichStringHandle.i, text$, FontHandle.i = 0) As "xlRichStringAddTextW"
  xlRichStringGetTextW(RichStringHandle.i, index, *FontHandle = 0)
  xlRichStringTextSize.i(RichStringHandle.i) As "xlRichStringTextSizeW"
  
  
EndImport

 Procedure.s xlPointerToString(pStr, format = #PB_Unicode)
   If(pStr)
     ProcedureReturn PeekS(pStr, -1, format)
   Else
     ProcedureReturn ""   
   EndIf
 EndProcedure

 Procedure.s xlBookGetSheetName(BookHandle.i, index.i = 0)
    ProcedureReturn xlPointerToString(xlBookGetSheetNameW(BookHandle, index))
 EndProcedure
  
 Procedure.s xlBookCustomNumFormat(BookHandle.i, fmt.i)
    ProcedureReturn xlPointerToString(xlBookCustomNumFormatW(BookHandle, fmt))
 EndProcedure
  
 Procedure.s xlBookDefaultFont(BookHandle.i, *fontSize)
   ProcedureReturn xlPointerToString(xlBookDefaultFontW(BookHandle, *fontSize))
 EndProcedure
    
 Procedure.s xlBookErrorMessage(BookHandle.i)
    ProcedureReturn xlPointerToString(xlBookErrorMessageW(BookHandle), #PB_Ascii)
 EndProcedure
  
 Procedure.s xlSheetReadStr(SheetHandle.i, row.i, col.i, *FormatHandle)
    ProcedureReturn xlPointerToString(xlSheetReadStrW(SheetHandle.i, row.i, col.i, *FormatHandle))
 EndProcedure
  
 Procedure.s xlSheetReadFormula(SheetHandle.i, row.i, col.i, *FormatHandle)
    ProcedureReturn xlPointerToString(xlSheetReadFormulaW(SheetHandle.i, row.i, col.i, *FormatHandle))
 EndProcedure
 
 Procedure.s xlSheetReadComment(SheetHandle.i, row.i, col.i)
   ProcedureReturn xlPointerToString(xlSheetReadCommentW(SheetHandle.i, row.i, col.i))   
 EndProcedure
 
 Procedure.s xlSheetHeader(SheetHandle)
   ProcedureReturn xlPointerToString(xlSheetHeaderW(SheetHandle))
 EndProcedure
 
 Procedure.s xlSheetFooter(SheetHandle)
   ProcedureReturn xlPointerToString(xlSheetFooterW(SheetHandle))
 EndProcedure
 
 Procedure.s xlSheetNamedRange(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *scopeId, *hidden)
   ProcedureReturn xlPointerToString(xlSheetNamedRangeW(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *scopeId, *hidden))
 EndProcedure
 
 Procedure.s xlSheetTable(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *headerRowCount, *totalsRowCount)
   ProcedureReturn xlPointerToString(xlSheetTableW(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast, *headerRowCount, *totalsRowCount))
 EndProcedure
 
 Procedure.s xlSheetHyperlink(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast)
   ProcedureReturn xlPointerToString(xlSheetHyperlinkW(SheetHandle, index, *rowFirst, *rowLast, *colFirst, *colLast))
 EndProcedure
 
 Procedure.s xlSheetName(SheetHandle)
   ProcedureReturn xlPointerToString(xlSheetNameW(SheetHandle))
 EndProcedure
 
 Procedure.s xlSheetRowColToAddr(SheetHandle, row, col, rowRelative, colRelative)
   ProcedureReturn xlPointerToString(xlSheetRowColToAddrW(SheetHandle, row, col, rowRelative, colRelative))
 EndProcedure
 
 Procedure.s xlSheetSelectionRange(SheetHandle)
   ProcedureReturn xlPointerToString(xlSheetSelectionRangeW(SheetHandle))
 EndProcedure
   
 Procedure.s xlFontName(BookHandle.i)
    ProcedureReturn PeekS(xlFontNameW(BookHandle))
 EndProcedure
  
 Procedure.s xlFilterColumnFilter(FilterColumnHandle.i, index)
    ProcedureReturn xlPointerToString(xlFilterColumnFilterW(FilterColumnHandle.i, index))
 EndProcedure
  
 Structure XLString
    s.s
 EndStructure
  
 Procedure.i xlFilterColumnGetCustomFilter(FilterColumnHandle.i, *op1, *v1.XLString, *op2, *v2.XLString, *andOp) 
    rVal = xlFilterColumnGetCustomFilterW(FilterColumnHandle.i, *op1, @v1ptr, *op2, @v2ptr, *andOp)   
    *v1\s = xlPointerToString(v1ptr)
    *v2\s = xlPointerToString(v2ptr)   
    ProcedureReturn rVal   
 EndProcedure
 
 Procedure.s xlRichStringGetText(FilterColumnHandle.i, index, *FontHandle = 0)
    ProcedureReturn xlPointerToString(xlRichStringGetTextW(FilterColumnHandle.i, index, *FontHandle))
 EndProcedure
  
 
 
 
; IDE Options = PureBasic 6.30 (Windows - x64)
; CursorPosition = 963
; FirstLine = 935
; Folding = ----
; EnableXP
; DPIAware
; DisableDebugger