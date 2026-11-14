///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                   LibXL .NET wrapper version 5.2.0                        //
//                                                                           //
//                 Copyright (c) 2008 - 2026 XLware s.r.o.                   //
//                                                                           //
//   THIS FILE AND THE SOFTWARE CONTAINED HEREIN IS PROVIDED 'AS IS' AND     //
//                COMES WITH NO WARRANTIES OF ANY KIND.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

namespace libxl
{
    public class Exception : System.Exception
    {
        public Exception(string message)
            : base("libxl: " + message)
        {
        }
    }
}
