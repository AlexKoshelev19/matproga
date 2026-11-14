#INCLUDE THIS ONCE

MACRO BookHandle   = DWORD
MACRO SheetHandle  = DWORD
MACRO FormatHandle = DWORD
MACRO FontHandle   = DWORD
MACRO AutoFilterHandle = DWORD
MACRO ConditionalFormatHandle = DWORD
MACRO ConditionalFormattingHandle = DWORD

ENUM COLOR SINGULAR
    COLOR_BLACK = 8
    COLOR_WHITE
    COLOR_RED
    COLOR_BRIGHTGREEN
    COLOR_BLUE
    COLOR_YELLOW
    COLOR_PINK
    COLOR_TURQUOISE
    COLOR_DARKRED
    COLOR_GREEN
    COLOR_DARKBLUE
    COLOR_DARKYELLOW
    COLOR_VIOLET
    COLOR_TEAL
    COLOR_GRAY25
    COLOR_GRAY50
    COLOR_PERIWINKLE_CF
    COLOR_PLUM_CF
    COLOR_IVORY_CF
    COLOR_LIGHTTURQUOISE_CF
    COLOR_DARKPURPLE_CF
    COLOR_CORAL_CF
    COLOR_OCEANBLUE_CF
    COLOR_ICEBLUE_CF
    COLOR_DARKBLUE_CL
    COLOR_PINK_CL
    COLOR_YELLOW_CL
    COLOR_TURQUOISE_CL
    COLOR_VIOLET_CL
    COLOR_DARKRED_CL
    COLOR_TEAL_CL
    COLOR_BLUE_CL
    COLOR_SKYBLUE
    COLOR_LIGHTTURQUOISE
    COLOR_LIGHTGREEN
    COLOR_LIGHTYELLOW
    COLOR_PALEBLUE
    COLOR_ROSE
    COLOR_LAVENDER
    COLOR_TAN
    COLOR_LIGHTBLUE
    COLOR_AQUA
    COLOR_LIME
    COLOR_GOLD
    COLOR_LIGHTORANGE
    COLOR_ORANGE
    COLOR_BLUEGRAY
    COLOR_GRAY40
    COLOR_DARKTEAL
    COLOR_SEAGREEN
    COLOR_DARKGREEN
    COLOR_OLIVEGREEN
    COLOR_BROWN
    COLOR_PLUM
    COLOR_INDIGO
    COLOR_GRAY80
    COLOR_DEFAULT_FOREGROUND = 64    '0x0040
    COLOR_DEFAULT_BACKGROUND = 65    '0x0041
    COLOR_TOOLTIP            = 81    '0x0051
    COLOR_AUTO               = 32767 '0x7FFF
END ENUM

ENUM NumFormat SINGULAR
    NUMFORMAT_GENERAL
    NUMFORMAT_NUMBER
    NUMFORMAT_NUMBER_D2
    NUMFORMAT_NUMBER_SEP
    NUMFORMAT_NUMBER_SEP_D2
    NUMFORMAT_CURRENCY_NEGBRA
    NUMFORMAT_CURRENCY_NEGBRARED
    NUMFORMAT_CURRENCY_D2_NEGBRA
    NUMFORMAT_CURRENCY_D2_NEGBRARED
    NUMFORMAT_PERCENT
    NUMFORMAT_PERCENT_D2
    NUMFORMAT_SCIENTIFIC_D2
    NUMFORMAT_FRACTION_ONEDIG
    NUMFORMAT_FRACTION_TWODIG
    NUMFORMAT_DATE
    NUMFORMAT_CUSTOM_D_MON_YY
    NUMFORMAT_CUSTOM_D_MON
    NUMFORMAT_CUSTOM_MON_YY
    NUMFORMAT_CUSTOM_HMM_AM
    NUMFORMAT_CUSTOM_HMMSS_AM
    NUMFORMAT_CUSTOM_HMM
    NUMFORMAT_CUSTOM_HMMSS
    NUMFORMAT_CUSTOM_MDYYYY_HMM
    NUMFORMAT_NUMBER_SEP_NEGBRA = 37
    NUMFORMAT_NUMBER_SEP_NEGBRARED
    NUMFORMAT_NUMBER_D2_SEP_NEGBRA
    NUMFORMAT_NUMBER_D2_SEP_NEGBRARED
    NUMFORMAT_ACCOUNT
    NUMFORMAT_ACCOUNTCUR
    NUMFORMAT_ACCOUNT_D2
    NUMFORMAT_ACCOUNT_D2_CUR
    NUMFORMAT_CUSTOM_MMSS
    NUMFORMAT_CUSTOM_H0MMSS
    NUMFORMAT_CUSTOM_MMSS0
    NUMFORMAT_CUSTOM_000P0E_PLUS0
    NUMFORMAT_TEXT
END ENUM

ENUM AlignH SINGULAR
    ALIGNH_GENERAL
    ALIGNH_LEFT
    ALIGNH_CENTER
    ALIGNH_RIGHT
    ALIGNH_FILL
    ALIGNH_JUSTIFY
    ALIGNH_MERGE
    ALIGNH_DISTRIBUTED
END ENUM

ENUM AlignV SINGULAR
    ALIGNV_TOP
    ALIGNV_CENTER
    ALIGNV_BOTTOM
    ALIGNV_JUSTIFY
    ALIGNV_DISTRIBUTED
END ENUM

ENUM BorderStyle SINGULAR
    BORDERSTYLE_NONE
    BORDERSTYLE_THIN
    BORDERSTYLE_MEDIUM
    BORDERSTYLE_DASHED
    BORDERSTYLE_DOTTED
    BORDERSTYLE_THICK
    BORDERSTYLE_DOUBLE
    BORDERSTYLE_HAIR
    BORDERSTYLE_MEDIUMDASHED
    BORDERSTYLE_DASHDOT
    BORDERSTYLE_MEDIUMDASHDOT
    BORDERSTYLE_DASHDOTDOT
    BORDERSTYLE_MEDIUMDASHDOTDOT
    BORDERSTYLE_SLANTDASHDOT
END ENUM

ENUM BorderDiagonal SINGULAR
    BORDERDIAGONAL_NONE
    BORDERDIAGONAL_DOWN
    BORDERDIAGONAL_UP
    BORDERDIAGONAL_BOTH
END ENUM

ENUM FillPattern SINGULAR
    FILLPATTERN_NONE
    FILLPATTERN_SOLID
    FILLPATTERN_GRAY50
    FILLPATTERN_GRAY75
    FILLPATTERN_GRAY25
    FILLPATTERN_HORSTRIPE
    FILLPATTERN_VERSTRIPE
    FILLPATTERN_REVDIAGSTRIPE
    FILLPATTERN_DIAGSTRIPE
    FILLPATTERN_DIAGCROSSHATCH
    FILLPATTERN_THICKDIAGCROSSHATCH
    FILLPATTERN_THINHORSTRIPE
    FILLPATTERN_THINVERSTRIPE
    FILLPATTERN_THINREVDIAGSTRIPE
    FILLPATTERN_THINDIAGSTRIPE
    FILLPATTERN_THINHORCROSSHATCH
    FILLPATTERN_THINDIAGCROSSHATCH
    FILLPATTERN_GRAY12P5
    FILLPATTERN_GRAY6P25
END ENUM

ENUM Script SINGULAR
    SCRIPT_NORMAL
    SCRIPT_SUPER
    SCRIPT_SUB
END ENUM

ENUM Underline SINGULAR
    UNDERLINE_NONE
    UNDERLINE_SINGLE
    UNDERLINE_DOUBLE
    UNDERLINE_SINGLEACC = 33
    UNDERLINE_DOUBLEACC = 34
END ENUM

ENUM SheetType SINGULAR
    SHEETTYPE_SHEET
    SHEETTYPE_CHART
    SHEETTYPE_UNKNOWN
END ENUM

ENUM CellType SINGULAR
    CELLTYPE_EMPTY
    CELLTYPE_NUMBER
    CELLTYPE_STRING
    CELLTYPE_BOOLEAN
    CELLTYPE_BLANK
    CELLTYPE_ERROR
END ENUM

ENUM ErrorType SINGULAR
     ERRORTYPE_NULL    = 0
     ERRORTYPE_DIV_0   = 7
     ERRORTYPE_VALUE   = 15
     ERRORTYPE_REF     = 23
     ERRORTYPE_NAME    = 29
     ERRORTYPE_NUM     = 36
     ERRORTYPE_NA      = 42
     ERRORTYPE_NOERROR = 255
END ENUM

ENUM PictureType SINGULAR
     PICTURETYPE_PNG
     PICTURETYPE_JPEG
     PICTURETYPE_WMF
     PICTURETYPE_DIB
     PICTURETYPE_EMF
     PICTURETYPE_PICT
     PICTURETYPE_TIFF
     PICTURETYPE_ERROR = 255
END ENUM

ENUM SheetState SINGULAR
    SHEETSTATE_VISIBLE
    SHEETSTATE_HIDDEN
    SHEETSTATE_VERYHIDDEN
END ENUM

ENUM Scope SINGULAR
    SCOPE_UNDEFINED = -2
    SCOPE_WORKBOOK  = -1
END ENUM

ENUM PAPER SINGULAR
    PAPER_DEFAULT
    PAPER_LETTER
    PAPER_LETTERSMALL
    PAPER_TABLOID
    PAPER_LEDGER
    PAPER_LEGAL
    PAPER_STATEMENT
    PAPER_EXECUTIVE
    PAPER_A3
    PAPER_A4
    PAPER_A4SMALL
    PAPER_A5
    PAPER_B4
    PAPER_B5
    PAPER_FOLIO
    PAPER_QUATRO
    PAPER_10x14
    PAPER_10x17
    PAPER_NOTE
    PAPER_ENVELOPE_9
    PAPER_ENVELOPE_10
    PAPER_ENVELOPE_11
    PAPER_ENVELOPE_12
    PAPER_ENVELOPE_14
    PAPER_C_SIZE
    PAPER_D_SIZE
    PAPER_E_SIZE
    PAPER_ENVELOPE_DL
    PAPER_ENVELOPE_C5
    PAPER_ENVELOPE_C3
    PAPER_ENVELOPE_C4
    PAPER_ENVELOPE_C6
    PAPER_ENVELOPE_C65
    PAPER_ENVELOPE_B4
    PAPER_ENVELOPE_B5
    PAPER_ENVELOPE_B6
    PAPER_ENVELOPE
    PAPER_ENVELOPE_MONARCH
    PAPER_US_ENVELOPE
    PAPER_FANFOLD
    PAPER_GERMAN_STD_FANFOLD
    PAPER_GERMAN_LEGAL_FANFOLD
    PAPER_B4_ISO
    PAPER_JAPANESE_POSTCARD
    PAPER_9x11
    PAPER_10x11
    PAPER_15x11
    PAPER_ENVELOPE_INVITE
    PAPER_US_LETTER_EXTRA = 50
    PAPER_US_LEGAL_EXTRA
    PAPER_US_TABLOID_EXTRA
    PAPER_A4_EXTRA
    PAPER_LETTER_TRANSVERSE
    PAPER_A4_TRANSVERSE
    PAPER_LETTER_EXTRA_TRANSVERSE
    PAPER_SUPERA
    PAPER_SUPERB
    PAPER_US_LETTER_PLUS
    PAPER_A4_PLUS
    PAPER_A5_TRANSVERSE
    PAPER_B5_TRANSVERSE
    PAPER_A3_EXTRA
    PAPER_A5_EXTRA
    PAPER_B5_EXTRA
    PAPER_A2
    PAPER_A3_TRANSVERSE
    PAPER_A3_EXTRA_TRANSVERSE
    PAPER_JAPANESE_DOUBLE_POSTCARD
    PAPER_A6
    PAPER_JAPANESE_ENVELOPE_KAKU2
    PAPER_JAPANESE_ENVELOPE_KAKU3
    PAPER_JAPANESE_ENVELOPE_CHOU3
    PAPER_JAPANESE_ENVELOPE_CHOU4
    PAPER_LETTER_ROTATED
    PAPER_A3_ROTATED
    PAPER_A4_ROTATED
    PAPER_A5_ROTATED
    PAPER_B4_ROTATED
    PAPER_B5_ROTATED
    PAPER_JAPANESE_POSTCARD_ROTATED
    PAPER_DOUBLE_JAPANESE_POSTCARD_ROTATED
    PAPER_A6_ROTATED
    PAPER_JAPANESE_ENVELOPE_KAKU2_ROTATED
    PAPER_JAPANESE_ENVELOPE_KAKU3_ROTATED
    PAPER_JAPANESE_ENVELOPE_CHOU3_ROTATED
    PAPER_JAPANESE_ENVELOPE_CHOU4_ROTATED
    PAPER_B6
    PAPER_B6_ROTATED
    PAPER_12x11
    PAPER_JAPANESE_ENVELOPE_YOU4
    PAPER_JAPANESE_ENVELOPE_YOU4_ROTATED
    PAPER_PRC16K
    PAPER_PRC32K
    PAPER_PRC32K_BIG
    PAPER_PRC_ENVELOPE1
    PAPER_PRC_ENVELOPE2
    PAPER_PRC_ENVELOPE3
    PAPER_PRC_ENVELOPE4
    PAPER_PRC_ENVELOPE5
    PAPER_PRC_ENVELOPE6
    PAPER_PRC_ENVELOPE7
    PAPER_PRC_ENVELOPE8
    PAPER_PRC_ENVELOPE9
    PAPER_PRC_ENVELOPE10
    PAPER_PRC16K_ROTATED
    PAPER_PRC32K_ROTATED
    PAPER_PRC32KBIG_ROTATED
    PAPER_PRC_ENVELOPE1_ROTATED
    PAPER_PRC_ENVELOPE2_ROTATED
    PAPER_PRC_ENVELOPE3_ROTATED
    PAPER_PRC_ENVELOPE4_ROTATED
    PAPER_PRC_ENVELOPE5_ROTATED
    PAPER_PRC_ENVELOPE6_ROTATED
    PAPER_PRC_ENVELOPE7_ROTATED
    PAPER_PRC_ENVELOPE8_ROTATED
    PAPER_PRC_ENVELOPE9_ROTATED
    PAPER_PRC_ENVELOPE10_ROTATED
END ENUM

ENUM EnhancedProtection SINGULAR
    PROT_DEFAULT = -1
    PROT_ALL = 0
    PROT_OBJECTS = 1
    PROT_SCENARIOS = 2
    PROT_FORMAT_CELLS = 4
    PROT_FORMAT_COLUMNS = 8
    PROT_FORMAT_ROWS = 16
    PROT_INSERT_COLUMNS = 32
    PROT_INSERT_ROWS = 64
    PROT_INSERT_HYPERLINKS = 128
    PROT_DELETE_COLUMNS = 256
    PROT_DELETE_ROWS = 512
    PROT_SEL_LOCKED_CELLS = 1024
    PROT_SORT = 2048
    PROT_AUTOFILTER = 4096
    PROT_PIVOTTABLES = 8192
    PROT_SEL_UNLOCKED_CELLS = 16384
END ENUM

ENUM CFormatType SINGULAR
    CFORMAT_BEGINWITH
    CFORMAT_CONTAINSBLANKS
    CFORMAT_CONTAINSERRORS
    CFORMAT_CONTAINSTEXT
    CFORMAT_DUPLICATEVALUES
    CFORMAT_ENDSWITH
    CFORMAT_EXPRESSION
    CFORMAT_NOTCONTAINSBLANKS
    CFORMAT_NOTCONTAINSERRORS
    CFORMAT_NOTCONTAINSTEXT
    CFORMAT_UNIQUEVALUES
END ENUM

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Book function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlCreateBook               LIB "libxl.dll" CDECL ALIAS "xlCreateBookCA"     _
                            () AS BookHandle
DECLARE FUNCTION xlCreateXMLBook            LIB "libxl.dll" CDECL ALIAS "xlCreateXMLBookCA"  _
                            () AS BookHandle

DECLARE FUNCTION xlBookLoad                 LIB "libxl.dll" CDECL ALIAS "xlBookLoadA"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookSave                 LIB "libxl.dll" CDECL ALIAS "xlBookSaveA"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookLoadRaw              LIB "libxl.dll" CDECL ALIAS "xlBookLoadRawA"     _
                            (BYVAL book AS BookHandle, BYREF fileData AS STRINGZ, BYVAL fileSize AS LONG) AS LONG
DECLARE FUNCTION xlBookSaveRaw              LIB "libxl.dll" CDECL ALIAS "xlBookSaveRawA"     _
                            (BYVAL book AS BookHandle, BYVAL fileData AS STRINGZ PTR, BYVAL fileSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddSheet             LIB "libxl.dll" CDECL ALIAS "xlBookAddSheetA"    _
                            (BYVAL book AS BookHandle, BYVAL sheetName AS STRING, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookInsertSheet          LIB "libxl.dll" CDECL ALIAS "xlBookInsertSheetA" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYREF sheetName AS STRINGZ, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookGetSheet             LIB "libxl.dll" CDECL ALIAS "xlBookGetSheetA"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS SheetHandle
DECLARE FUNCTION xlBookSheetType            LIB "libxl.dll" CDECL ALIAS "xlBookSheetTypeA"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookDelSheet             LIB "libxl.dll" CDECL ALIAS "xlBookDelSheetA"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookSheetCount           LIB "libxl.dll" CDECL ALIAS "xlBookSheetCountA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookAddFormat            LIB "libxl.dll" CDECL ALIAS "xlBookAddFormatA"          _
                            (BYVAL book AS BookHandle, BYVAL initFormat AS FormatHandle) AS FormatHandle
DECLARE FUNCTION xlBookAddFont              LIB "libxl.dll" CDECL ALIAS "xlBookAddFontA"            _
                            (BYVAL book AS BookHandle, BYVAL initFont AS FontHandle) AS FontHandle
DECLARE FUNCTION xlBookAddCustomNumFormat   LIB "libxl.dll" CDECL ALIAS "xlBookAddCustomNumFormatA" _
                            (BYVAL book AS BookHandle, BYREF customNumFormat AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookCustomNumFormat LIB "libxl.dll" CDECL ALIAS "xlBookCustomNumFormatA"         _                     'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL format AS LONG) AS DWORD

DECLARE FUNCTION xlBookFormat               LIB "libxl.dll" CDECL ALIAS "xlBookFormatA"      _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FormatHandle
DECLARE FUNCTION xlBookFormatSize           LIB "libxl.dll" CDECL ALIAS "xlBookFormatSizeA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookFont                 LIB "libxl.dll" CDECL ALIAS "xlBookFontA"        _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FontHandle
DECLARE FUNCTION xlBookFontSize             LIB "libxl.dll" CDECL ALIAS "xlBookFontSizeA"    _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookDatePack             LIB "libxl.dll" CDECL ALIAS "xlBookDatePackA"    _
                            (BYVAL book AS BookHandle, BYVAL year AS LONG, BYVAL month AS LONG, BYVAL day AS LONG, BYVAL hour AS LONG, BYVAL minute AS LONG, BYVAL second AS LONG, BYVAL millisecond AS LONG) AS DOUBLE
DECLARE FUNCTION xlBookDateUnpack           LIB "libxl.dll" CDECL ALIAS "xlBookDateUnpackA"  _
                            (BYVAL book AS BookHandle, BYVAL value AS DOUBLE, BYVAL year AS LONG PTR, BYVAL month AS LONG PTR, BYVAL day AS LONG PTR, _
                             BYVAL hour AS LONG PTR, BYVAL minute AS LONG PTR, BYVAL second AS LONG PTR, BYVAL millisecond AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookColorPack            LIB "libxl.dll" CDECL ALIAS "xlBookColorPackA"    _
                            (BYVAL book AS BookHandle, BYVAL red AS LONG, BYVAL green AS LONG, BYVAL blue AS LONG) AS LONG
DECLARE FUNCTION xlBookColorUnpack          LIB "libxl.dll" CDECL ALIAS "xlBookColorUnpackA"  _
                            (BYVAL book AS BookHandle, BYVAL value AS LONG, BYVAL red AS LONG PTR, BYVAL green AS LONG PTR, BYVAL blue AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookActiveSheet          LIB "libxl.dll" CDECL ALIAS "xlBookActiveSheetA"    _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookSetActiveSheet       LIB "libxl.dll" CDECL ALIAS "xlBookSetActiveSheetA" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG

DECLARE FUNCTION xlBookPictureSize          LIB "libxl.dll" CDECL ALIAS "xlBookPictureSizeA"  _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookGetPicture           LIB "libxl.dll" CDECL ALIAS "xlBookGetPictureA"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYVAL picData AS STRINGZ PTR, BYVAL picSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddPicture           LIB "libxl.dll" CDECL ALIAS "xlBookAddPictureA"   _
                            (BYVAL book AS BookHandle, BYREF filename AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookAddPicture2          LIB "libxl.dll" CDECL ALIAS "xlBookAddPicture2A"  _
                            (BYVAL book AS BookHandle, BYREF picData AS STRINGZ, BYVAL picSize AS LONG) AS LONG

DECLARE FUNCTION xlBookDefaultFont          LIB "libxl.dll" CDECL ALIAS "xlBookDefaultFontA"    _                         'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL fontSize AS LONG PTR) AS DWORD
DECLARE FUNCTION xlBookSetDefaultFont       LIB "libxl.dll" CDECL ALIAS "xlBookSetDefaultFontA" _
                            (BYVAL book AS BookHandle, BYREF fontName AS STRINGZ, BYVAL fontSize AS LONG) AS LONG

DECLARE FUNCTION xlBookRefR1C1              LIB "libxl.dll" CDECL ALIAS "xlBookRefR1C1A"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookSetRefR1C1           LIB "libxl.dll" CDECL ALIAS "xlBookSetRefR1C1A"   _
                            (BYVAL book AS BookHandle, BYVAL refR1C1 AS LONG) AS LONG

DECLARE FUNCTION xlBookSetKey               LIB "libxl.dll" CDECL ALIAS "xlBookSetKeyA"       _
                            (BYVAL book AS BookHandle, BYREF keyname AS STRINGZ, BYREF key AS STRINGZ) AS LONG

DECLARE FUNCTION xlBookRgbMode              LIB "libxl.dll" CDECL ALIAS "xlBookRgbModeA"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookSetRgbMode           LIB "libxl.dll" CDECL ALIAS "xlBookSetRgbModeA"   _
                            (BYVAL book AS BookHandle, BYVAL rgbMode AS LONG) AS LONG

DECLARE FUNCTION xlBookVersion              LIB "libxl.dll" CDECL ALIAS "xlBookVersionA"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookBiffVersion          LIB "libxl.dll" CDECL ALIAS "xlBookBiffVersionA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookIsDate1904           LIB "libxl.dll" CDECL ALIAS "xlBookIsDate1904A"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookSetDate1904          LIB "libxl.dll" CDECL ALIAS "xlBookSetDate1904A"  _
                            (BYVAL book AS BookHandle, BYVAL date1904 AS LONG) AS LONG

DECLARE FUNCTION xlBookIsTemplate           LIB "libxl.dll" CDECL ALIAS "xlBookIsTemplateA"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookSetTemplate          LIB "libxl.dll" CDECL ALIAS "xlBookSetTemplateA"  _
                            (BYVAL book AS BookHandle, BYVAL tmpl AS LONG) AS LONG

DECLARE FUNCTION xlBookSetLocale            LIB "libxl.dll" CDECL ALIAS "xlBookSetLocaleA"    _
                            (BYVAL book AS BookHandle, BYREF tmpl AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookErrorMessage         LIB "libxl.dll" CDECL ALIAS "xlBookErrorMessageA" _                          'check this function for sure
                            (BYVAL book AS BookHandle) AS DWORD

DECLARE FUNCTION xlBookRelease              LIB "libxl.dll" CDECL ALIAS "xlBookReleaseA"      _
                            (BYVAL book AS BookHandle) AS LONG

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Sheet function declarations''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                                                                                                         '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                                                                                                         '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlSheetCellType      LIB "libxl.dll" CDECL ALIAS "xlSheetCellTypeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetIsFormula      LIB "libxl.dll" CDECL ALIAS "xlSheetIsFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG

DECLARE FUNCTION xlSheetCellFormat      LIB "libxl.dll" CDECL ALIAS "xlSheetCellFormatA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS FormatHandle
DECLARE FUNCTION xlSheetSetCellFormat      LIB "libxl.dll" CDECL ALIAS "xlSheetSetCellFormatA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle) AS LONG

Declare Function xlSheetReadStr      Lib "libxl.dll" CDecl Alias "xlSheetReadStrA"         _
                            (ByVal sheet As SheetHandle, ByVal row As Long, ByVal col As Long, ByVal format As FormatHandle Pointer) As Dword

DECLARE FUNCTION xlSheetWriteStr      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteStrA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadNum      LIB "libxl.dll" CDECL ALIAS "xlSheetReadNumA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) AS DOUBLE
DECLARE FUNCTION xlSheetWriteNum      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteNumA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS DOUBLE, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadBool      LIB "libxl.dll" CDECL ALIAS "xlSheetReadBoolA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBool      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteBoolA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS LONG, BYVAL format AS FormatHandle ) AS LONG


DECLARE FUNCTION xlSheetReadBlank      LIB "libxl.dll" CDECL ALIAS "xlSheetReadBlankA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBlank      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteBlankA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadFormula      LIB "libxl.dll" CDECL ALIAS "xlSheetReadFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) AS DWORD
DECLARE FUNCTION xlSheetWriteFormula      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadComment      LIB "libxl.dll" CDECL ALIAS "xlSheetReadCommentA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS DWORD
DECLARE FUNCTION xlSheetWriteComment      LIB "libxl.dll" CDECL ALIAS "xlSheetWriteCommentA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYREF author AS STRINGZ, BYVAL width_ AS LONG, BYVAL height_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetIsDate      LIB "libxl.dll" CDECL ALIAS "xlSheetIsDateA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetReadError      LIB "libxl.dll" CDECL ALIAS "xlSheetReadErrorA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetColWidth      LIB "libxl.dll" CDECL ALIAS "xlSheetColWidthA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS DOUBLE
'                           (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS DOUBLE
DECLARE FUNCTION xlSheetRowHeight      LIB "libxl.dll" CDECL ALIAS "xlSheetRowHeightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetSetCol      LIB "libxl.dll" CDECL ALIAS "xlSheetSetColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, BYVAL width AS DOUBLE, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRow      LIB "libxl.dll" CDECL ALIAS "xlSheetSetRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL height AS DOUBLE, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetRowHidden      LIB "libxl.dll" CDECL ALIAS "xlSheetRowHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRowHidden      LIB "libxl.dll" CDECL ALIAS "xlSheetSetRowHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetColHidden      LIB "libxl.dll" CDECL ALIAS "xlSheetColHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetColHidden      LIB "libxl.dll" CDECL ALIAS "xlSheetSetColHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL hidden AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetMerge      LIB "libxl.dll" CDECL ALIAS "xlSheetGetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetMerge      LIB "libxl.dll" CDECL ALIAS "xlSheetSetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelMerge      LIB "libxl.dll" CDECL ALIAS "xlSheetDelMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetMergeSize      LIB "libxl.dll" CDECL ALIAS "xlSheetMergeSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetMerge      LIB "libxl.dll" CDECL ALIAS "xlSheetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetDelMergeByIndex      LIB "libxl.dll" CDECL ALIAS "xlSheetDelMergeByIndexA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG


DECLARE FUNCTION xlSheetPictureSize      LIB "libxl.dll" CDECL ALIAS "xlSheetPictureSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetGetPicture      LIB "libxl.dll" CDECL ALIAS "xlSheetGetPictureA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowTop AS LONG PTR, BYVAL colLeft AS LONG PTR, BYVAL rowBottom AS LONG PTR, BYVAL colRight AS LONG PTR _
                                                                             , BYVAL width AS LONG PTR , BYVAL height AS LONG PTR , BYVAL offset_x AS LONG PTR , BYVAL offset_y AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetPicture      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPictureA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL scale AS DOUBLE, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetPicture2      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPicture2A"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL width AS LONG, BYVAL height AS LONG, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetHorPageBreak      LIB "libxl.dll" CDECL ALIAS "xlSheetGetHorPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetHorPageBreakSize      LIB "libxl.dll" CDECL ALIAS "xlSheetGetHorPageBreakSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetGetVerPageBreak      LIB "libxl.dll" CDECL ALIAS "xlSheetGetVerPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetVerPageBreakSize      LIB "libxl.dll" CDECL ALIAS "xlSheetGetVerPageBreakSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetSetHorPageBreak      LIB "libxl.dll" CDECL ALIAS "xlSheetSetHorPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL pageBreak AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetVerPageBreak      LIB "libxl.dll" CDECL ALIAS "xlSheetSetVerPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL pageBreak AS LONG) AS LONG


DECLARE FUNCTION xlSheetSplit      LIB "libxl.dll" CDECL ALIAS "xlSheetSplitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetSplitInfo      LIB "libxl.dll" CDECL ALIAS "xlSheetSplitInfoA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR) AS LONG


DECLARE FUNCTION xlSheetGroupRows      LIB "libxl.dll" CDECL ALIAS "xlSheetGroupRowsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL collapsed AS LONG) AS LONG
DECLARE FUNCTION xlSheetGroupCols      LIB "libxl.dll" CDECL ALIAS "xlSheetGroupColsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, BYVAL collapsed AS LONG) AS LONG


DECLARE FUNCTION xlSheetGroupSummaryBelow      LIB "libxl.dll" CDECL ALIAS "xlSheetGroupSummaryBelowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetGroupSummaryBelow      LIB "libxl.dll" CDECL ALIAS "xlSheetSetGroupSummaryBelowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL below AS LONG) AS LONG


DECLARE FUNCTION xlSheetGroupSummaryRight      LIB "libxl.dll" CDECL ALIAS "xlSheetGroupSummaryRightA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetGroupSummaryRight      LIB "libxl.dll" CDECL ALIAS "xlSheetSetGroupSummaryRightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL right AS LONG) AS LONG


DECLARE FUNCTION xlSheetClear      LIB "libxl.dll" CDECL ALIAS "xlSheetClearA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetInsertCol      LIB "libxl.dll" CDECL ALIAS "xlSheetInsertColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetInsertRow      LIB "libxl.dll" CDECL ALIAS "xlSheetInsertRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveCol      LIB "libxl.dll" CDECL ALIAS "xlSheetRemoveColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveRow      LIB "libxl.dll" CDECL ALIAS "xlSheetRemoveRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetCopyCell      LIB "libxl.dll" CDECL ALIAS "xlSheetCopyCellA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowSrc AS LONG, BYVAL colSrc AS LONG, BYVAL rowDst AS LONG, BYVAL colDst AS LONG) AS LONG


DECLARE FUNCTION xlSheetFirstRow      LIB "libxl.dll" CDECL ALIAS "xlSheetFirstRowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastRow      LIB "libxl.dll" CDECL ALIAS "xlSheetLastRowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetFirstCol      LIB "libxl.dll" CDECL ALIAS "xlSheetFirstColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastCol      LIB "libxl.dll" CDECL ALIAS "xlSheetLastColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetDisplayGridlines      LIB "libxl.dll" CDECL ALIAS "xlSheetDisplayGridlinesA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetDisplayGridlines      LIB "libxl.dll" CDECL ALIAS "xlSheetSetDisplayGridlinesA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL show AS LONG) AS LONG


DECLARE FUNCTION xlSheetPrintGridlines      LIB "libxl.dll" CDECL ALIAS "xlSheetPrintGridlinesA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetPrintGridlines      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintGridlinesA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL print AS LONG) AS LONG


DECLARE FUNCTION xlSheetZoom      LIB "libxl.dll" CDECL ALIAS "xlSheetZoomA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetZoom      LIB "libxl.dll" CDECL ALIAS "xlSheetSetZoomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG) AS LONG


DECLARE FUNCTION xlSheetPrintZoom      LIB "libxl.dll" CDECL ALIAS "xlSheetPrintZoomA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetPrintZoom      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintZoomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetPrintFit      LIB "libxl.dll" CDECL ALIAS "xlSheetGetPrintFitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG PTR, BYVAL hPages AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetPrintFit      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintFitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG, BYVAL hPages AS LONG) AS LONG


DECLARE FUNCTION xlSheetLandscape      LIB "libxl.dll" CDECL ALIAS "xlSheetLandscapeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetLandscape      LIB "libxl.dll" CDECL ALIAS "xlSheetSetLandscapeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL landscape AS LONG) AS LONG


DECLARE FUNCTION xlSheetPaper      LIB "libxl.dll" CDECL ALIAS "xlSheetPaperA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetPaper      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPaperA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL paper AS LONG) AS LONG


DECLARE FUNCTION xlSheetHeader      LIB "libxl.dll" CDECL ALIAS "xlSheetHeaderA"         _
                            (BYVAL sheet AS SheetHandle) AS DWORD
DECLARE FUNCTION xlSheetSetHeader      LIB "libxl.dll" CDECL ALIAS "xlSheetSetHeaderA"         _
                            (BYVAL sheet AS SheetHandle, BYREF header AS STRINGZ, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetHeaderMargin      LIB "libxl.dll" CDECL ALIAS "xlSheetHeaderMarginA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE


DECLARE FUNCTION xlSheetFooter      LIB "libxl.dll" CDECL ALIAS "xlSheetFooterA"         _
                            (BYVAL sheet AS SheetHandle) AS DWORD
DECLARE FUNCTION xlSheetSetFooter      LIB "libxl.dll" CDECL ALIAS "xlSheetSetFooterA"         _
                            (BYVAL sheet AS SheetHandle, BYREF footer AS STRINGZ, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetFooterMargin      LIB "libxl.dll" CDECL ALIAS "xlSheetFooterMarginA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetHCenter      LIB "libxl.dll" CDECL ALIAS "xlSheetHCenterA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetHCenter      LIB "libxl.dll" CDECL ALIAS "xlSheetSetHCenterA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hCenter AS LONG) AS LONG


DECLARE FUNCTION xlSheetVCenter      LIB "libxl.dll" CDECL ALIAS "xlSheetVCenterA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetVCenter      LIB "libxl.dll" CDECL ALIAS "xlSheetSetVCenterA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL vCenter AS LONG) AS LONG


DECLARE FUNCTION xlSheetMarginLeft      LIB "libxl.dll" CDECL ALIAS "xlSheetMarginLeftA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE FUNCTION xlSheetSetMarginLeft      LIB "libxl.dll" CDECL ALIAS "xlSheetSetMarginLeftA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL margin AS DOUBLE) AS LONG


DECLARE FUNCTION xlSheetMarginRight      LIB "libxl.dll" CDECL ALIAS "xlSheetMarginRightA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE FUNCTION xlSheetSetMarginRight      LIB "libxl.dll" CDECL ALIAS "xlSheetSetMarginRightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL margin AS DOUBLE) AS LONG


DECLARE FUNCTION xlSheetMarginTop      LIB "libxl.dll" CDECL ALIAS "xlSheetMarginTopA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE FUNCTION xlSheetSetMarginTop      LIB "libxl.dll" CDECL ALIAS "xlSheetSetMarginTopA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL margin AS DOUBLE) AS LONG


DECLARE FUNCTION xlSheetMarginBottom      LIB "libxl.dll" CDECL ALIAS "xlSheetMarginBottomA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE FUNCTION xlSheetSetMarginBottom      LIB "libxl.dll" CDECL ALIAS "xlSheetSetMarginBottomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL margin AS DOUBLE) AS LONG


DECLARE FUNCTION xlSheetPrintRowCol      LIB "libxl.dll" CDECL ALIAS "xlSheetPrintRowColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetPrintRowCol      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintRowColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL print AS LONG) AS LONG


DECLARE FUNCTION xlSheetSetPrintRepeatRows      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintRepeatRowsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetPrintRepeatCols      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintRepeatColsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetPrintArea      LIB "libxl.dll" CDECL ALIAS "xlSheetSetPrintAreaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetClearPrintRepeats      LIB "libxl.dll" CDECL ALIAS "xlSheetClearPrintRepeatsA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetClearPrintArea      LIB "libxl.dll" CDECL ALIAS "xlSheetClearPrintAreaA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetGetNamedRange      LIB "libxl.dll" CDECL ALIAS "xlSheetGetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) AS LONG
DECLARE FUNCTION xlSheetSetNamedRange      LIB "libxl.dll" CDECL ALIAS "xlSheetSetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, _
                             BYVAL scopeId AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelNamedRange      LIB "libxl.dll" CDECL ALIAS "xlSheetDelNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL scopeId AS LONG) AS LONG

DECLARE FUNCTION xlSheetNamedRangeSize      LIB "libxl.dll" CDECL ALIAS "xlSheetNamedRangeSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetNamedRange      LIB "libxl.dll" CDECL ALIAS "xlSheetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) AS DWORD


DECLARE FUNCTION xlSheetHyperlinkSize      LIB "libxl.dll" CDECL ALIAS "xlSheetHyperlinkSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetHyperlink      LIB "libxl.dll" CDECL ALIAS "xlSheetHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS DWORD
DECLARE FUNCTION xlSheetDelHyperlink      LIB "libxl.dll" CDECL ALIAS "xlSheetDelHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetAddHyperlink      LIB "libxl.dll" CDECL ALIAS "xlSheetAddHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYREF hyperlink AS STRINGZ, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetName      LIB "libxl.dll" CDECL ALIAS "xlSheetNameA"         _
                            (BYVAL sheet AS SheetHandle) AS DWORD
DECLARE FUNCTION xlSheetSetName      LIB "libxl.dll" CDECL ALIAS "xlSheetSetNameA"         _
                            (BYVAL sheet AS SheetHandle, BYREF sheetName AS STRINGZ) AS LONG


DECLARE FUNCTION xlSheetProtect      LIB "libxl.dll" CDECL ALIAS "xlSheetProtectA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetProtect      LIB "libxl.dll" CDECL ALIAS "xlSheetSetProtectA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL protect AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetProtectEx    LIB "libxl.dll" CDECL ALIAS "xlSheetSetProtectExA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL protect AS LONG, BYREF password AS STRINGZ, BYVAL prot AS LONG) AS LONG


DECLARE FUNCTION xlSheetHidden     LIB "libxl.dll" CDECL ALIAS "xlSheetHiddenA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetHidden     LIB "libxl.dll" CDECL ALIAS "xlSheetSetHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hidden AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetTopLeftView     LIB "libxl.dll" CDECL ALIAS "xlSheetGetTopLeftViewA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetTopLeftView     LIB "libxl.dll" CDECL ALIAS "xlSheetSetTopLeftViewA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetRightToLeft     LIB "libxl.dll" CDECL ALIAS "xlSheetRightToLeftA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetRightToLeft     LIB "libxl.dll" CDECL ALIAS "xlSheetSetRightToLeftA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rightToLeft AS LONG) AS LONG


DECLARE FUNCTION xlSheetAddrToRowCol     LIB "libxl.dll" CDECL ALIAS "xlSheetAddrToRowColA"         _
                            (BYVAL sheet AS SheetHandle, BYREF addr_ AS STRINGZ, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR, _
                             BYVAL rowRelative AS LONG PTR, BYVAL colRelative AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetRowColToAddr     LIB "libxl.dll" CDECL ALIAS "xlSheetRowColToAddrA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowRelative AS LONG, BYVAL colRelative AS LONG) AS DWORD


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Format function declarations'''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFormatFont    LIB "libxl.dll" CDECL ALIAS "xlFormatFontA"      _
                            (BYVAL format AS FormatHandle) AS FontHandle
DECLARE FUNCTION xlFormatSetFont LIB "libxl.dll" CDECL ALIAS "xlFormatSetFontA"      _
                            (BYVAL format AS FormatHandle, BYVAL font AS FontHandle) AS LONG

DECLARE FUNCTION xlFormatNumFormat    LIB "libxl.dll" CDECL ALIAS "xlFormatNumFormatA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetNumFormat LIB "libxl.dll" CDECL ALIAS "xlFormatSetNumFormatA"      _
                            (BYVAL format AS FormatHandle, BYVAL numFormat AS LONG) AS LONG

DECLARE FUNCTION xlFormatAlignH    LIB "libxl.dll" CDECL ALIAS "xlFormatAlignHA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetAlignH LIB "libxl.dll" CDECL ALIAS "xlFormatSetAlignHA"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG) AS LONG

DECLARE FUNCTION xlFormatAlignV    LIB "libxl.dll" CDECL ALIAS "xlFormatAlignVA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetAlignV LIB "libxl.dll" CDECL ALIAS "xlFormatSetAlignVA"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG) AS LONG

DECLARE FUNCTION xlFormatWrap    LIB "libxl.dll" CDECL ALIAS "xlFormatWrapA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetWrap LIB "libxl.dll" CDECL ALIAS "xlFormatSetWrapA"      _
                            (BYVAL format AS FormatHandle, BYVAL wrap AS LONG) AS LONG

DECLARE FUNCTION xlFormatRotation     LIB "libxl.dll" CDECL ALIAS "xlFormatRotationA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetRotation  LIB "libxl.dll" CDECL ALIAS "xlFormatSetRotationA"      _
                            (BYVAL format AS FormatHandle, BYVAL rotation AS LONG) AS LONG

DECLARE FUNCTION xlFormatIndent     LIB "libxl.dll" CDECL ALIAS "xlFormatIndentA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetIndent  LIB "libxl.dll" CDECL ALIAS "xlFormatSetIndentA"      _
                            (BYVAL format AS FormatHandle, BYVAL indent AS LONG) AS LONG

DECLARE FUNCTION xlFormatShrinkToFit     LIB "libxl.dll" CDECL ALIAS "xlFormatShrinkToFitA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetShrinkToFit  LIB "libxl.dll" CDECL ALIAS "xlFormatSetShrinkToFitA"      _
                            (BYVAL format AS FormatHandle, BYVAL shrinkToFit AS LONG) AS LONG

DECLARE FUNCTION xlFormatSetBorder     LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG
DECLARE FUNCTION xlFormatSetBorderColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderLeft     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderLeftA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderLeft  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderLeftA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderRight     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderRightA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderRight  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderRightA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderTop     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderTopA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderTop  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderTopA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderBottom     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderBottomA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderBottom  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderBottomA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderLeftColor     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderLeftColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderLeftColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderLeftColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderRightColor     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderRightColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderRightColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderRightColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderTopColor     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderTopColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderTopColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderTopColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderBottomColor     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderBottomColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderBottomColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderBottomColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderDiagonal     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderDiagonalA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderDiagonal  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderDiagonalA"      _
                            (BYVAL format AS FormatHandle, BYVAL border AS LONG) AS LONG

DECLARE FUNCTION xlFormatSetBorderDiagonalColor LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderDiagonalColorA" _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatBorderDiagonalStyle     LIB "libxl.dll" CDECL ALIAS "xlFormatBorderDiagonalStyleA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetBorderDiagonalStyle  LIB "libxl.dll" CDECL ALIAS "xlFormatSetBorderDiagonalStyleA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatFillPattern     LIB "libxl.dll" CDECL ALIAS "xlFormatFillPatternA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetFillPattern  LIB "libxl.dll" CDECL ALIAS "xlFormatSetFillPatternA"      _
                            (BYVAL format AS FormatHandle, BYVAL pattern AS LONG) AS LONG

DECLARE FUNCTION xlFormatPatternForegroundColor     LIB "libxl.dll" CDECL ALIAS "xlFormatPatternForegroundColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetPatternForegroundColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetPatternForegroundColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatPatternBackgroundColor     LIB "libxl.dll" CDECL ALIAS "xlFormatPatternBackgroundColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetPatternBackgroundColor  LIB "libxl.dll" CDECL ALIAS "xlFormatSetPatternBackgroundColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG) AS LONG

DECLARE FUNCTION xlFormatLocked     LIB "libxl.dll" CDECL ALIAS "xlFormatLockedA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetLocked  LIB "libxl.dll" CDECL ALIAS "xlFormatSetLockedA"      _
                            (BYVAL format AS FormatHandle, BYVAL locked AS LONG) AS LONG

DECLARE FUNCTION xlFormatHidden     LIB "libxl.dll" CDECL ALIAS "xlFormatHiddenA"         _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetHidden  LIB "libxl.dll" CDECL ALIAS "xlFormatSetHiddenA"      _
                            (BYVAL format AS FormatHandle, BYVAL hidden AS LONG) AS LONG

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Font function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFontSize    LIB "libxl.dll" CDECL ALIAS "xlFontSizeA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetSize LIB "libxl.dll" CDECL ALIAS "xlFontSetSizeA"      _
                            (BYVAL font AS FontHandle, BYVAL fontsize AS LONG) AS LONG

DECLARE FUNCTION xlFontItalic    LIB "libxl.dll" CDECL ALIAS "xlFontItalicA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetItalic LIB "libxl.dll" CDECL ALIAS "xlFontSetItalicA"      _
                            (BYVAL font AS FontHandle, BYVAL italic AS LONG) AS LONG

DECLARE FUNCTION xlFontStrikeOut    LIB "libxl.dll" CDECL ALIAS "xlFontStrikeOutA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetStrikeOut LIB "libxl.dll" CDECL ALIAS "xlFontSetStrikeOutA"      _
                            (BYVAL font AS FontHandle, BYVAL strikeOut AS LONG) AS LONG

DECLARE FUNCTION xlFontColor    LIB "libxl.dll" CDECL ALIAS "xlFontColorA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetColor LIB "libxl.dll" CDECL ALIAS "xlFontSetColorA"      _
                            (BYVAL font AS FontHandle, BYVAL fColor AS LONG) AS LONG

DECLARE FUNCTION xlFontBold    LIB "libxl.dll" CDECL ALIAS "xlFontBoldA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetBold LIB "libxl.dll" CDECL ALIAS "xlFontSetBoldA"      _
                            (BYVAL font AS FontHandle, BYVAL bold AS LONG) AS LONG

DECLARE FUNCTION xlFontScript    LIB "libxl.dll" CDECL ALIAS "xlFontScriptA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetScript LIB "libxl.dll" CDECL ALIAS "xlFontSetScriptA"      _
                            (BYVAL font AS FontHandle, BYVAL script AS LONG) AS LONG

DECLARE FUNCTION xlFontUnderline    LIB "libxl.dll" CDECL ALIAS "xlFontUnderlineA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE FUNCTION xlFontSetUnderline LIB "libxl.dll" CDECL ALIAS "xlFontSetUnderlineA"      _
                            (BYVAL font AS FontHandle, BYVAL underline AS LONG) AS LONG

DECLARE FUNCTION xlFontName    LIB "libxl.dll" CDECL ALIAS "xlFontNameA"      _
                            (ByVal Font As FontHandle) As Dword
DECLARE FUNCTION xlFontSetName LIB "libxl.dll" CDECL ALIAS "xlFontSetNameA"      _
                            (BYVAL font AS FontHandle, BYREF fontName AS STRINGZ) AS LONG
' ----

declare function xlSheetSetAutoFitArea LIB "libxl.dll" CDECL ALIAS "xlSheetSetAutoFitAreaA"      _
                            (byval sheet as SheetHandle, byval rowFirst as long, byval colFirst as long, byval rowLast as long, byval colLast as long) as long

declare function xlSheetAutoFilter LIB "libxl.dll" CDECL ALIAS "xlSheetAutoFilterA" _
                            (byval sheet as SheetHandle) as AutoFilterHandle

declare sub xlAutoFilterSetRef LIB "libxl.dll" CDECL ALIAS "xlAutoFilterSetRefA"      _
                            (byval filter as AutoFilterHandle, byval rowFirst as long, byval rowLast as long, byval colFirst as long, byval colLast as long)

declare function xlAutoFilterSetSort LIB "libxl.dll" CDECL ALIAS "xlAutoFilterSetSortA"      _
                            (byval filter as AutoFilterHandle, byval columnIndex as long, byval descending as long) as long

declare function xlAutoFilterAddSort LIB "libxl.dll" CDECL ALIAS "xlAutoFilterAddSortA"      _
                            (byval filter as AutoFilterHandle, byval columnIndex as long, byval descending as long) as long

declare sub xlSheetApplyFilter LIB "libxl.dll" CDECL ALIAS "xlSheetApplyFilterA"      _
                            (byval sheet as SheetHandle)

declare sub xlSheetRemoveFilter LIB "libxl.dll" CDECL ALIAS "xlSheetRemoveFilterA"      _
                            (byval sheet as SheetHandle)

declare sub xlSheetSetActiveCell LIB "libxl.dll" CDECL ALIAS "xlSheetSetActiveCellA"      _
                            (byval sheet as SheetHandle, byval row as long, byval col as long)

declare function xlBookMoveSheet LIB "libxl.dll" CDECL ALIAS "xlBookMoveSheetA" _
                            (byval book as BookHandle, byval srcIndex as long, byval dstIndex as long) as long

declare function xlSheetGetActiveCell LIB "libxl.dll" CDECL ALIAS "xlSheetGetActiveCellA" _
                            (byval sheet as SheetHandle, byval row as long ptr, byval col as long ptr) as long

declare function xlBookLoadInfo LIB "libxl.dll" CDECL ALIAS "xlBookLoadInfoA" _
                            (byval book as BookHandle, BYREF fileName AS STRINGZ) as long

DECLARE FUNCTION xlSheetLastFilledRow LIB "libxl.dll" CDECL ALIAS "xlSheetLastFilledRowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG

DECLARE FUNCTION xlSheetLastFilledCol LIB "libxl.dll" CDECL ALIAS "xlSheetLastFilledColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG

DECLARE FUNCTION xlSheetColWidthPx LIB "libxl.dll" CDECL ALIAS "xlSheetColWidthPxA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS long) AS LONG

DECLARE FUNCTION xlSheetRowHeightPx LIB "libxl.dll" CDECL ALIAS "xlSheetRowHeightPxA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS long) AS LONG

DECLARE FUNCTION xlBookCalcMode LIB "libxl.dll" CDECL ALIAS "xlBookCalcModeA"         _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookSetCalcMode LIB "libxl.dll" CDECL ALIAS "xlBookSetCalcModeA"         _
                            (BYVAL book AS BookHandle, BYVAL calcmode AS long) AS LONG

DECLARE FUNCTION xlBookRemoveVBA LIB "libxl.dll" CDECL ALIAS "xlBookRemoveVBAA"         _
                            (BYVAL book AS BookHandle) AS LONG

declare function xlBookAddConditionalFormat LIB "libxl.dll" CDECL ALIAS "xlBookAddConditionalFormatA" (byval book as BookHandle) as ConditionalFormatHandle
declare function xlSheetAddConditionalFormatting LIB "libxl.dll" CDECL ALIAS "xlSheetAddConditionalFormattingA" (byval sheet as SheetHandle) as ConditionalFormattingHandle

declare sub xlConditionalFormatSetFillPattern LIB "libxl.dll" CDECL ALIAS "xlConditionalFormatSetFillPatternA" (byval cformat as ConditionalFormatHandle,byval pattern as long)
declare sub xlConditionalFormatSetPatternBackgroundColor LIB "libxl.dll" CDECL ALIAS "xlConditionalFormatSetPatternBackgroundColorA" (byval cformat as ConditionalFormatHandle,byval colo as long)

declare sub xlConditionalFormattingAddRange LIB "libxl.dll" CDECL ALIAS "xlConditionalFormattingAddRangeA" (byval cformatting as ConditionalFormattingHandle,byval rowFirst as long,byval rowLast as long,byval colFirst as long,byval colLast as long)
declare sub xlConditionalFormattingAddRule LIB "libxl.dll" CDECL ALIAS "xlConditionalFormattingAddRuleA" (byval cformatting as ConditionalFormattingHandle,byval typ as long,byval cformat as ConditionalFormatHandle,byval expr as string,byval stopiftrue as long)
