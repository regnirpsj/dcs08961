// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/io.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/io.hpp"

// includes, system

#include <array>                  // std::array<>
#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <iomanip>                // std::setfill, std::setw
#include <ostream>                // std::ostream
#include <sstream>                // std::ostringstream

// includes, project

#include <platform/win32/utilities.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {
  
  namespace win32 {
  
    // variables, exported
  
    // functions, exported

    std::ostream&
    operator<<(std::ostream& os, DEVMODE const& a)
    {
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        boost::io::ios_all_saver const ias(os);
      
        os << '['
          /* << "dmDeviceName:"    */                     << a.dmDeviceName    << '/'
          /* << "dmSpecVersion:"   */ << "0x" << std::hex << a.dmSpecVersion   << '/'
          /* << "dmDriverVersion:" */ << "0x" << std::hex << a.dmDriverVersion << ',';

        {
          static std::array<unsigned const, 30> const fields = {
            {
              DM_ORIENTATION,
              DM_PAPERSIZE,
              DM_PAPERLENGTH,
              DM_PAPERWIDTH,
              DM_SCALE,
              DM_COPIES,
              DM_DEFAULTSOURCE,
              DM_PRINTQUALITY,
              DM_DISPLAYORIENTATION,
              DM_DISPLAYFIXEDOUTPUT,
              DM_COLOR,
              DM_DUPLEX,
              DM_YRESOLUTION,
              DM_TTOPTION,
              DM_COLLATE,
              DM_FORMNAME,
              DM_LOGPIXELS,
              DM_POSITION,
              DM_PELSWIDTH,
              DM_PELSHEIGHT,
              DM_BITSPERPEL,
              DM_DISPLAYFLAGS,
              DM_NUP,
              DM_DISPLAYFREQUENCY,
              DM_ICMMETHOD,
              DM_ICMINTENT,
              DM_MEDIATYPE,
              DM_DITHERTYPE,
              DM_PANNINGWIDTH,
              DM_PANNINGHEIGHT,
            }
          };

          std::ostringstream ostr;
        
          for (auto f : fields) {
            if ((a.dmFields & f) || (DM_DISPLAYFIXEDOUTPUT & f) || (DM_POSITION & f)) {
              switch (f) {
              case DM_ORIENTATION:
                ostr << "dmOrientation:" << ',';
                break;
              case DM_PAPERSIZE:
                ostr << "dmPapersize:" << ',';
                break;
              case DM_PAPERLENGTH:
                ostr << "dmPaperLength:" << ',';
                break;
              case DM_PAPERWIDTH:
                ostr << "dmPaperWidth:" << ',';
                break;
              case DM_SCALE:
                ostr << "dmScale:" << ',';
                break;
              case DM_COPIES:
                ostr << "dmCopies:" << ',';
                break;
              case DM_DEFAULTSOURCE:
                ostr << "dmDefaultSource:" << ',';
                break;
              case DM_PRINTQUALITY:
                ostr << "dmPrintQuality:" << ',';
                break;
              case DM_POSITION:
                {
                  boost::io::ios_all_saver const ias(os);
                
                  ostr // << "dmPosition:"
                    << '['
                    << std::right << std::setw(4) << std::setfill(' ') << a.dmPosition.x << ','
                    << std::right << std::setw(4) << std::setfill(' ') << a.dmPosition.y << "],";
                }
                break;
              case DM_DISPLAYORIENTATION:
                {
                  if (DMDO_DEFAULT != a.dmDisplayOrientation) {
                    // ostr << "dmDisplayOrientation:";
                  
                    switch (a.dmDisplayOrientation) {
                    case DMDO_DEFAULT: ostr << "DEFAULT"; break;
                    case DMDO_90:      ostr << "  90DEG";     break;
                    case DMDO_180:     ostr << " 180DEG";     break;
                    case DMDO_270:     ostr << " 270DEG";     break;
                    default:           ostr << "UNKNOWN"; break;
                    }
                  
                    ostr << ',';
                  }
                }
                break;
              case DM_DISPLAYFIXEDOUTPUT:
                {
                  // ostr << "dmDisplayFixedOutput:";

                  switch (a.dmDisplayFixedOutput) {
                  case DMDFO_DEFAULT: ostr << "DEFAULT"; break;
                  case DMDFO_CENTER:  ostr << " CENTER"; break;
                  case DMDFO_STRETCH: ostr << "STRETCH"; break;
                  default:            ostr << "UNKNOWN"; break;
                  }
                
                  ostr << ',';
                }
                break;
              case DM_COLOR:
                ostr << "dmColor:" << ',';
                break;
              case DM_DUPLEX:
                ostr << "dmDuplex:" << ',';
                break;
              case DM_YRESOLUTION:
                ostr << "dmYResolution:" << ',';
                break;
              case DM_TTOPTION:
                ostr << "dmTTOption:" << ',';
                break;
              case DM_COLLATE:
                ostr << "dmCollate:" << ',';
                break;
              case DM_FORMNAME:
                ostr << "dmFormName:" << ',';
                break;
              case DM_LOGPIXELS:
                {
                  boost::io::ios_all_saver const ias(os);
                
                  ostr // << "dmLogPixels:"
                    << std::right << std::setw(2) << std::setfill(' ')
                    << a.dmLogPixels << "dpi,";
                }
                break;
              case DM_BITSPERPEL:
                {
                  boost::io::ios_all_saver const ias(os);
                
                  ostr // << "dmBitsPerPel:"
                    << std::right << std::setw(2) << std::setfill(' ') << a.dmBitsPerPel << "BPP,";
                }
                break;
              case DM_PELSWIDTH:
                {
                  boost::io::ios_all_saver const ias(os);
                
                  ostr // << "dmPelsWidth:"
                    << std::right << std::setw(4) << std::setfill(' ') << a.dmPelsWidth
                    << " x "
                    << std::right << std::setw(4) << std::setfill(' ') << a.dmPelsHeight
                    << ',';
                }
                break;
              case DM_PELSHEIGHT:
                // see DM_PELSWIDTH
                break;
              case DM_DISPLAYFLAGS:
                {
                  ostr // << "dmDisplayFlags:"
                    << "COLOR,";

#if 0
                  // windows sdk 8:wingdi.h: DM_GRAYSCALE no longer valid
                  if (DM_GRAYSCALE & a.dmDisplayFlags) {
                    ostr << "GRAYSCALE,";
                  } else {
                    ostr << "COLOR,";
                  }
#endif
                
                  if (DM_INTERLACED & a.dmDisplayFlags) {
                    ostr << "INTERLACED,";
                  } else {
                    ostr << "NON-INTERLACED,";
                  }
                }
                break;
              case DM_NUP:
                ostr << "dmNup:" << ',';
                break;
              case DM_DISPLAYFREQUENCY:
                {
                  boost::io::ios_all_saver const ias(os);
                
                  ostr // << "dmDisplayFrequency:"
                    << std::right << std::setw(3) << std::setfill(' ')
                    << a.dmDisplayFrequency << "Hz,";
                }
                break;
              case DM_ICMMETHOD:
                ostr << "dmICMMethod:" << ',';
                break;
              case DM_ICMINTENT:
                ostr << "dmICMIntent:" << ',';
                break;
              case DM_MEDIATYPE:
                ostr << "dmMediaType:" << ',';
                break;
              case DM_DITHERTYPE:
                ostr << "dmDitherType:" << ',';
                break;
              case DM_PANNINGWIDTH:
                ostr << "dmPanningWidth:" << a.dmPanningWidth << ',';
                break;
              case DM_PANNINGHEIGHT:
                ostr << "dmPanningHeight:" << a.dmPanningHeight << ',';
                break;
              default:
                ostr << "dmUnknown (" << f << "),";
                break;
              }
            }
          }

          if (ostr.str().empty()) {
            ostr << "dmNone";
          } else {
            ostr << '\b';
          }

          os << ostr.str(); // << " (" << std::hex << a.dmFields << ')';
        }
      
        os << ']';
      }

      return os;
    }
  
  std::ostream&
  operator<<(std::ostream& os, DISPLAY_DEVICE const& a)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      boost::io::ios_all_saver const ias(os);
      
      os << "["
         << "id:"   << a.DeviceID     << ','
         << "key:"  << a.DeviceKey    << ','
         << "name:" << a.DeviceName   << ','
         << "str:"  << a.DeviceString << ','
         << "flags:";

      {
        std::ostringstream ostr;

        static std::array<std::pair<unsigned const, std::string const>, 6> const state_flags = {
          {
            std::make_pair(DISPLAY_DEVICE_ACTIVE,           "ACTIVE"),
            std::make_pair(DISPLAY_DEVICE_MIRRORING_DRIVER, "MIRRORING_DRIVER"),
            std::make_pair(DISPLAY_DEVICE_MODESPRUNED,      "MODESPRUNED"),
            std::make_pair(DISPLAY_DEVICE_PRIMARY_DEVICE,   "PRIMARY_DEVICE"),
            std::make_pair(DISPLAY_DEVICE_REMOVABLE,        "REMOVABLE"),
            std::make_pair(DISPLAY_DEVICE_VGA_COMPATIBLE,   "VGA_COMPATIBLE"),
          }
        };

        for (auto s : state_flags) {
          if (s.first & a.StateFlags) {
            ostr << s.second << '|';
          }
        }

        if (ostr.str().empty()) {
          ostr << "NONE";
        } else {
          ostr << '\b';
        }

        os << ostr.str() << " (" << std::hex << a.StateFlags << ')';
      }

      os << ']';
    }

    return os;
  }

  std::ostream&
  operator<<(std::ostream& os, LUID const& a)
  {
    std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      os << '['
         << "lo:" << a.LowPart << ",hi:" << a.HighPart
         << ']';
    }

    return os;
  }
  
  std::ostream&
  operator<<(std::ostream& os, MONITORINFOEX const& a)
  {
    std::ostream::sentry const cerberus(os);

    if (cerberus) {
      os << '['
         << "mon:" << a.rcMonitor << ','
         << "wrk:" << a.rcWork    << ','
         << ((MONITORINFOF_PRIMARY & a.dwFlags) ? "" : "!") << "primary,"
         << "dev:" << a.szDevice
         << ']';
    }

    return os;
  }
  
  std::ostream&
  operator<<(std::ostream& os, HWND const& a)
  {
    std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      HINSTANCE* const instance(window_long_ptr<HINSTANCE>(a, GWLP_HINSTANCE));

      if (instance) {
        boost::io::ios_all_saver const ias(os);

        os << '['
           << "inst:@0x" << std::setfill('0') << std::setw(8) << instance << ',';
        
        {
          HWND* const parent(window_long_ptr<HWND>(a, GWLP_HWNDPARENT));
          
          if (parent) {
            os << "parent:@0x" << std::setfill('0') << std::setw(8) << parent;
          } else {
            os << "parent:none";
          }
        }

        os << ',';
        
        {
          DWORD const style(class_long<DWORD>(a, GCL_STYLE));
          
          os << "class:"; // 0x" << std::setfill('0') << std::setw(8) << style << '(';
          
          if (style) {
            static std::array<std::pair<unsigned const, std::string const>, 11> const class_styles = {
              {
                std::make_pair(CS_BYTEALIGNCLIENT, "BYTEALIGNCLIENT"),
                std::make_pair(CS_BYTEALIGNWINDOW, "BYTEALIGNWINDOW"),
                std::make_pair(CS_CLASSDC,         "CLASSDC"),
                std::make_pair(CS_DBLCLKS,         "DBLCLKS"),
                std::make_pair(CS_GLOBALCLASS,     "GLOBALCLASS"),
                std::make_pair(CS_HREDRAW,         "HREDRAW"),
                std::make_pair(CS_NOCLOSE,         "NOCLOSE"),
                std::make_pair(CS_OWNDC,           "OWNDC"),
                std::make_pair(CS_PARENTDC,        "PARENTDC"),
                std::make_pair(CS_SAVEBITS,        "SAVEBITS"),
                std::make_pair(CS_VREDRAW,         "VREDRAW"),
              }
            };
            
            for (auto s : class_styles) {
              if (s.first & style) {
                os << s.second << '|';
              }
            }
            
            os << '\b';
          } else {
            os << "NONE";
          }
          
          // os << ')';
        }

        os << ',';
        
        {
          DWORD const style(window_long<DWORD>(a, GWL_STYLE));
          
          os << "style:"; // 0x" << std::setfill('0') << std::setw(8) << style << '(';
        
          if (style) {
            static std::array<std::pair<unsigned const, std::string const>, 17> const window_styles = {
              {
                std::make_pair(WS_BORDER,       "BORDER"),
                std::make_pair(WS_CHILD,        "CHILD"),
                std::make_pair(WS_CLIPCHILDREN, "CLIPCHILDREN"),
                std::make_pair(WS_CLIPSIBLINGS, "CLIPSIBLINGS"),
                std::make_pair(WS_DLGFRAME,     "DLGFRAME"),
                std::make_pair(WS_DISABLED,     "DISABLED"),
                std::make_pair(WS_GROUP,        "GROUP"),
                std::make_pair(WS_HSCROLL,      "HSCROLL"),
                std::make_pair(WS_MAXIMIZE,     "MAXIMIZE"),
                std::make_pair(WS_MINIMIZE,     "MINIMIZE"),
                std::make_pair(WS_OVERLAPPED,   "OVERLAPPED"),
                std::make_pair(WS_POPUP,        "POPUP"),
                std::make_pair(WS_SYSMENU,      "SYSMENU"),
                std::make_pair(WS_TABSTOP,      "TABSTOP"),
                std::make_pair(WS_THICKFRAME,   "THICKFRAME"),
                std::make_pair(WS_VSCROLL,      "VSCROLL"),
                std::make_pair(WS_VISIBLE,      "VISIBLE"),
              }
            };
            
            for (auto s : window_styles) {
              if (s.first & style) {
                os << s.second << '|';
              }
            }
            
            os << '\b';
          } else {
            os << "NONE";
          }

          // os << ')';
        }

        os << ',';
        
        {
          DWORD const style(window_long<DWORD>(a, GWL_EXSTYLE));
          
          os << "exstyle:"; // 0x" << std::setfill('0') << std::setw(8) << style << '(';
          
          if (style) {
            static std::array<std::pair<unsigned const, std::string const>, 17> const window_exstyles = {
              {
                std::make_pair(WS_EX_ACCEPTFILES,    "ACCEPTFILES"),
                std::make_pair(WS_EX_APPWINDOW,      "APPWINDOW"),
                std::make_pair(WS_EX_CLIENTEDGE,     "CLIENTEDGE"),
                std::make_pair(WS_EX_CONTEXTHELP,    "CONTEXTHELP"),
                std::make_pair(WS_EX_CONTROLPARENT,  "CONTROLPARENT"),
                std::make_pair(WS_EX_DLGMODALFRAME,  "DLGMODALFRAME"),
                std::make_pair(WS_EX_LEFTSCROLLBAR,  "LEFTSCROLLBAR"),
                std::make_pair(WS_EX_MDICHILD,       "MDICHILD"),
                std::make_pair(WS_EX_NOPARENTNOTIFY, "NOPARENTNOTIFY"),
                std::make_pair(WS_EX_RIGHT,          "RIGHT"),
                std::make_pair(WS_EX_RIGHTSCROLLBAR, "RIGHTSCROLLBAR"),
                std::make_pair(WS_EX_RTLREADING,     "RTLREADING"),
                std::make_pair(WS_EX_STATICEDGE,     "STATICEDGE"),
                std::make_pair(WS_EX_TOOLWINDOW,     "TOOLWINDOW"),
                std::make_pair(WS_EX_TOPMOST,        "TOPMOST"),
                std::make_pair(WS_EX_TRANSPARENT,    "TRANSPARENT"),
                std::make_pair(WS_EX_WINDOWEDGE,     "WINDOWEDGE"),
              }
            };
            
            for (auto s : window_exstyles) {
              if (s.first & style) {
                os << s.second << '|';
              }
            }
            
            os << '\b';
          } else {
            os << "NONE";
          }
          
          // os << ')';
        }
        
        os << ']';
      } else {
        os << "[inst:none]";
      }
    }
    
    return os;
  }

  std::ostream&
  operator<<(std::ostream& os, RECT const& a)
  {
    std::ostream::sentry const cerberus(os);
    
    if (cerberus) {
      os << '['
         << "l:" << a.left   << ','
         << "t:" << a.top    << ','
         << "r:" << a.right  << ','
         << "b:" << a.bottom
         << ']';
    }
  
    return os;
  }
    
  } // namespace win32 {
  
} // namespace platform {
