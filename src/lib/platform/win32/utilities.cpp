// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/utilities.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#if defined(WIN32_LEAN_AND_MEAN)
#  undef WIN32_LEAN_AND_MEAN
#endif

#include "platform/win32/utilities.hpp"

// includes, system

#include <iomanip>       // std::setfill, std::setw
#include <sstream>       // ostringstream
#include <stdexcept>     // std::runtime_error
#include <unordered_map> // std::unordered_map<>
#include <vector>        // std::vector<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using wm_message_map_type = std::unordered_map<unsigned, std::string>;
  
  // variables, internal
  
  wm_message_map_type const wm_message_map = {
    {
      { WM_ACTIVATE, "WM_ACTIVATE" },
      { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" },
      { WM_APP, "WM_APP" },
      { WM_ASKCBFORMATNAME, "WM_ASKCBFORMATNAME" },
      { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" },
      { WM_CANCELMODE, "WM_CANCELMODE" },
      { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" },
      { WM_CHANGECBCHAIN, "WM_CHANGECBCHAIN" },
      { WM_CHAR, "WM_CHAR" },
      { WM_CHARTOITEM, "WM_CHARTOITEM" },
      { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" },
      { WM_CLEAR, "WM_CLEAR" },
      { WM_CLOSE, "WM_CLOSE" },
      // { WM_COALESCE_FIRST, "WM_COALESCE_FIRST" },
      // { WM_COALESCE_LAST, "WM_COALESCE_LAST" },
      { WM_COMMAND, "WM_COMMAND" },
      { WM_COMPACTING, "WM_COMPACTING" },
      { WM_COMPAREITEM, "WM_COMPAREITEM" },
      { WM_CONTEXTMENU, "WM_CONTEXTMENU" },
      { WM_COPY, "WM_COPY" },
      { WM_COPYDATA, "WM_COPYDATA" },
      { WM_CREATE, "WM_CREATE" },
      // { WM_CTLCOLOR, "WM_CTLCOLOR" },
      { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" },
      { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" },
      { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" },
      { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" },
      { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" },
      { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" },
      { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" },
      { WM_CUT, "WM_CUT" },
      { WM_DDE_ACK, "WM_DDE_ACK" },
      { WM_DDE_ADVISE, "WM_DDE_ADVISE" },
      { WM_DDE_DATA, "WM_DDE_DATA" },
      { WM_DDE_EXECUTE, "WM_DDE_EXECUTE" },
      { WM_DDE_FIRST, "WM_DDE_FIRST" },
      { WM_DDE_INITIATE, "WM_DDE_INITIATE" },
      { WM_DDE_LAST, "WM_DDE_LAST" },
      { WM_DDE_POKE, "WM_DDE_POKE" },
      { WM_DDE_REQUEST, "WM_DDE_REQUEST" },
      { WM_DDE_TERMINATE, "WM_DDE_TERMINATE" },
      { WM_DDE_UNADVISE, "WM_DDE_UNADVISE" },
      { WM_DEADCHAR, "WM_DEADCHAR" },
      { WM_DELETEITEM, "WM_DELETEITEM" },
      { WM_DESTROY, "WM_DESTROY" },
      { WM_DESTROYCLIPBOARD, "WM_DESTROYCLIPBOARD" },
      { WM_DEVICECHANGE, "WM_DEVICECHANGE" },
      { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" },
      { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" },
      { WM_DRAWCLIPBOARD, "WM_DRAWCLIPBOARD" },
      { WM_DRAWITEM, "WM_DRAWITEM" },
      { WM_DROPFILES, "WM_DROPFILES" },
      { 0x031f, "WM_DWMNCRENDERINGCHANGED" },
      { WM_ENABLE, "WM_ENABLE" },
      { WM_ENDSESSION, "WM_ENDSESSION" },
      { WM_ENTERIDLE, "WM_ENTERIDLE" },
      { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" },
      { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" },
      { WM_ERASEBKGND, "WM_ERASEBKGND" },
      { WM_EXITMENULOOP, "WM_EXITMENULOOP" },
      { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" },
      { WM_FONTCHANGE, "WM_FONTCHANGE" },
      { WM_GETDLGCODE, "WM_GETDLGCODE" },
      { WM_GETFONT, "WM_GETFONT" },
      { WM_GETHOTKEY, "WM_GETHOTKEY" },
      { WM_GETICON, "WM_GETICON" },
      { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" },
      { WM_GETTEXT, "WM_GETTEXT" },
      { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" },
      { WM_HANDHELDFIRST, "WM_HANDHELDFIRST" },
      { WM_HANDHELDLAST, "WM_HANDHELDLAST" },
      { WM_HELP, "WM_HELP" },
      { WM_HOTKEY, "WM_HOTKEY" },
      { WM_HSCROLL, "WM_HSCROLL" },
      { WM_HSCROLLCLIPBOARD, "WM_HSCROLLCLIPBOARD" },
      { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" },
      { WM_IME_CHAR, "WM_IME_CHAR" },
      { WM_IME_COMPOSITION, "WM_IME_COMPOSITION" },
      { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" },
      { WM_IME_CONTROL, "WM_IME_CONTROL" },
      { WM_IME_ENDCOMPOSITION, "WM_IME_ENDCOMPOSITION" },
      { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" },
      { WM_IME_KEYLAST, "WM_IME_KEYLAST" },
      { WM_IME_KEYUP, "WM_IME_KEYUP" },
      { WM_IME_NOTIFY, "WM_IME_NOTIFY" },
      { WM_IME_SELECT, "WM_IME_SELECT" },
      { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" },
      { WM_IME_STARTCOMPOSITION, "WM_IME_STARTCOMPOSITION" },
      { WM_INITDIALOG, "WM_INITDIALOG" },
      { WM_INITMENU, "WM_INITMENU" },
      { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" },
      { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" },
      { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" },
      { WM_KEYDOWN, "WM_KEYDOWN" },
      { WM_KEYFIRST, "WM_KEYFIRST" },
      { WM_KEYLAST, "WM_KEYLAST" },
      { WM_KEYUP, "WM_KEYUP" },
      { WM_KILLFOCUS, "WM_KILLFOCUS" },
      { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" },
      { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" },
      { WM_LBUTTONUP, "WM_LBUTTONUP" },
      { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" },
      { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" },
      { WM_MBUTTONUP, "WM_MBUTTONUP" },
      { WM_MDIACTIVATE, "WM_MDIACTIVATE" },
      { WM_MDICASCADE, "WM_MDICASCADE" },
      { WM_MDICREATE, "WM_MDICREATE" },
      { WM_MDIDESTROY, "WM_MDIDESTROY" },
      { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" },
      { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" },
      { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" },
      { WM_MDINEXT, "WM_MDINEXT" },
      { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" },
      { WM_MDIRESTORE, "WM_MDIRESTORE" },
      { WM_MDISETMENU, "WM_MDISETMENU" },
      { WM_MDITILE, "WM_MDITILE" },
      { WM_MEASUREITEM, "WM_MEASUREITEM" },
      { WM_MENUCHAR, "WM_MENUCHAR" },
      { WM_MENUSELECT, "WM_MENUSELECT" },
      { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" },
      { WM_MOUSEFIRST, "WM_MOUSEFIRST" },
      { WM_MOUSEHOVER, "WM_MOUSEHOVER" },
      { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" },
      { WM_MOUSELEAVE, "WM_MOUSELEAVE" },
      { WM_MOUSEMOVE, "WM_MOUSEMOVE" },
      { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" },
      { WM_MOVE, "WM_MOVE" },
      { WM_MOVING, "WM_MOVING" },
      { WM_NCACTIVATE, "WM_NCACTIVATE" },
      { WM_NCCALCSIZE, "WM_NCCALCSIZE" },
      { WM_NCCREATE, "WM_NCCREATE" },
      { WM_NCDESTROY, "WM_NCDESTROY" },
      { WM_NCHITTEST, "WM_NCHITTEST" },
      { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" },
      { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" },
      { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" },
      { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" },
      { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" },
      { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" },
      { WM_NCMOUSELEAVE, "WM_NCMOUSELEAVE" },
      { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" },
      { WM_NCPAINT, "WM_NCPAINT" },
      { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" },
      { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" },
      { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" },
      { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" },
      { WM_NEXTMENU, "WM_NEXTMENU" },
      { WM_NOTIFY, "WM_NOTIFY" },
      { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" },
      { WM_NULL, "WM_NULL" },
      { WM_PAINT, "WM_PAINT" },
      { WM_PAINTCLIPBOARD, "WM_PAINTCLIPBOARD" },
      { WM_PAINTICON, "WM_PAINTICON" },
      { WM_PALETTECHANGED, "WM_PALETTECHANGED" },
      { WM_PALETTEISCHANGING, "WM_PALETTEISCHANGING" },
      { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" },
      { WM_PASTE, "WM_PASTE" },
      { WM_PENWINFIRST, "WM_PENWINFIRST" },
      { WM_PENWINLAST, "WM_PENWINLAST" },
      { WM_POWER, "WM_POWER" },
      { WM_POWERBROADCAST, "WM_POWERBROADCAST" },
      { WM_PRINT, "WM_PRINT" },
      { WM_PRINTCLIENT, "WM_PRINTCLIENT" },
      { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" },
      { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" },
      { WM_QUERYNEWPALETTE, "WM_QUERYNEWPALETTE" },
      { WM_QUERYOPEN, "WM_QUERYOPEN" },
      { WM_QUEUESYNC, "WM_QUEUESYNC" },
      { WM_QUIT, "WM_QUIT" },
      { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" },
      { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" },
      { WM_RBUTTONUP, "WM_RBUTTONUP" },
      { WM_RENDERALLFORMATS, "WM_RENDERALLFORMATS" },
      { WM_RENDERFORMAT, "WM_RENDERFORMAT" },
      { WM_SETCURSOR, "WM_SETCURSOR" },
      { WM_SETFOCUS, "WM_SETFOCUS" },
      { WM_SETFONT, "WM_SETFONT" },
      { WM_SETHOTKEY, "WM_SETHOTKEY" },
      { WM_SETICON, "WM_SETICON" },
      { WM_SETREDRAW, "WM_SETREDRAW" },
      { WM_SETTEXT, "WM_SETTEXT" },
      { WM_SETTINGCHANGE, "WM_SETTINGCHANGE" },
      { WM_SHOWWINDOW, "WM_SHOWWINDOW" },
      { WM_SIZE, "WM_SIZE" },
      { WM_SIZECLIPBOARD, "WM_SIZECLIPBOARD" },
      { WM_SIZING, "WM_SIZING" },
      { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" },
      { WM_STYLECHANGED, "WM_STYLECHANGED" },
      { WM_STYLECHANGING, "WM_STYLECHANGING" },
      { WM_SYSCHAR, "WM_SYSCHAR" },
      { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" },
      { WM_SYSCOMMAND, "WM_SYSCOMMAND" },
      { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" },
      { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" },
      { WM_SYSKEYUP, "WM_SYSKEYUP" },
      // { WM_SYSTEMERROR, "WM_SYSTEMERROR" },
      { WM_TCARD, "WM_TCARD" },
      { WM_TIMECHANGE, "WM_TIMECHANGE" },
      { WM_TIMER, "WM_TIMER" },
      // [https://social.msdn.microsoft.com/Forums/windowsapps/en-US/f677f319-9f02-4438-92fb-6e776924425d/windowproc-and-messages-0x90-0x91-0x92-0x93]
      { 0x0090, "WM_UAHDESTROYWINDOW" },
      { 0x0091, "WM_UAHDRAWMENU" },
      { 0x0092, "WM_UAHDRAWMENUITEM" }, 
      { 0x0093, "WM_UAHINITMENU" },
      { 0x0094, "WM_UAHMEASUREMENUITEM" },
      { 0x0095, "WM_UAHNCPAINTMENUPOPUP" },
      { WM_UNDO, "WM_UNDO" },
      { WM_USER, "WM_USER" },
      { WM_USERCHANGED, "WM_USERCHANGED" },
      { WM_VKEYTOITEM, "WM_VKEYTOITEM" },
      { WM_VSCROLL, "WM_VSCROLL" },
      { WM_VSCROLLCLIPBOARD, "WM_VSCROLLCLIPBOARD" },
      { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" },
      { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" },
      { WM_WININICHANGE, "WM_WININICHANGE" },
    }
  };

  // functions, internal

} // namespace {

namespace platform {
  
  namespace win32 {
  
    // variables, exported
  
    // functions, exported

    /**
     *
     */
    std::string
    wm_message_string(unsigned msg)
    {
      std::string message("unknown message");
      auto const  found  (wm_message_map.find(msg));
      
      if (wm_message_map.end() != found) {
        message = found->second;
      }
      
      else if ((0xC000 < msg) && (0xFFFF > msg)) {
        char result[128]; 
        
        if (0 < ::GetClipboardFormatName(msg, result, sizeof(result))) {
          message = result;
        }
      }
      
      std::ostringstream ostr;
      
      ostr << message
           << " (0x" << std::setfill('0') << std::setw(4) << std::hex << msg << ')';
      
      return ostr.str();
    }
    
    /**
     * see [http://msdn.microsoft.com/en-us/library/windows/desktop/ms683197(v=vs.85).aspx]
     */
    std::string
    module_path(HMODULE module)
    {
      TRACE("platform::win32::module_path");
      
      std::vector<char> path(MAX_PATH);
      unsigned          len (::GetModuleFileNameA(module, &path[0], unsigned(path.size())));

      while (len == path.size()) {
        path.resize(path.size() * 2);
        path.clear ();
      
        len = ::GetModuleFileNameA(module, &path[0], unsigned(path.size()));
      }

      if (0 == len) {
        throw std::runtime_error("GetModuleFileNameA() failed!");
      }
    
      return std::string(path.begin(), path.begin() + len);
    }

    /**
     *
     */
    std::string
    last_error_message()
    {
      TRACE("platform::win32::last_error_message");
    
      static unsigned const format_flags(FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                                         FORMAT_MESSAGE_FROM_SYSTEM |
                                         FORMAT_MESSAGE_IGNORE_INSERTS);
    
      unsigned const lerr(::GetLastError());
      char*          msg_buf;
      unsigned       msg_len(::FormatMessage(format_flags,
                                             nullptr,
                                             lerr,
                                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                             reinterpret_cast<LPTSTR>(&msg_buf), 0,
                                             nullptr));
    
      std::ostringstream ostr;
    
      ostr << '(' << lerr << '|' << std::string(msg_buf, msg_buf+msg_len-2) << ')';
    
      ::LocalFree(msg_buf);

      return ostr.str();
    }
    
  } // namespace win32 {
  
} // namespace platform {
