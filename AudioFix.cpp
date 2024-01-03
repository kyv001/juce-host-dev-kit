#define JUCE_CORE_INCLUDE_OBJC_HELPERS 1
#define JUCE_CORE_INCLUDE_COM_SMART_PTR 1
#define JUCE_CORE_INCLUDE_NATIVE_HEADERS 1
#define JUCE_CORE_INCLUDE_JNI_HELPERS 1

#include <juce_core/juce_core.h>
#include <juce_osc/juce_osc.h>

#include <cctype>
#include <cstdarg>
#include <locale>
#include <thread>

#if ! (JUCE_ANDROID || JUCE_BSD)
#include <sys/timeb.h>
#include <cwctype>
#endif

#if JUCE_WINDOWS
#include <ctime>

#if JUCE_MINGW
#include <ws2spi.h>
#include <cstdio>
#include <locale.h>
#else
JUCE_BEGIN_IGNORE_WARNINGS_MSVC(4091)
#include <Dbghelp.h>
JUCE_END_IGNORE_WARNINGS_MSVC

#if ! JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
#pragma comment (lib, "DbgHelp.lib")
#endif
#endif

#else
#if JUCE_LINUX || JUCE_BSD || JUCE_ANDROID
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <unistd.h>
#include <netinet/in.h>
#endif

#if JUCE_WASM
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/stat.h>
#endif

#if JUCE_LINUX || JUCE_BSD
#include <stdio.h>
#include <langinfo.h>
#include <ifaddrs.h>
#include <sys/resource.h>

#if JUCE_USE_CURL
#include <curl/curl.h>
#endif
#endif

#include <pwd.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <net/if.h>
#include <sys/ioctl.h>

#if ! (JUCE_ANDROID || JUCE_WASM)
#include <execinfo.h>
#endif
#endif

#if JUCE_MAC || JUCE_IOS
#include <xlocale.h>
#include <mach/mach.h>
#endif

#if JUCE_ANDROID
#include <ifaddrs.h>
#include <android/log.h>
#endif

#undef check

#include <juce_core/text/juce_String.cpp>
#include <juce_core/streams/juce_OutputStream.cpp>
#include <juce_core/streams/juce_MemoryOutputStream.cpp>
#include <juce_core/files/juce_common_MimeTypes.h>
#include <juce_core/files/juce_common_MimeTypes.cpp>
#include <juce_core/native/juce_AndroidDocument_android.cpp>
#include <juce_osc/osc/juce_OSCTypes.cpp>

#if JUCE_WINDOWS
#include <juce_core/native/juce_Files_windows.cpp>
#endif

#if JUCE_LINUX
#include <juce_core/native/juce_CommonFile_linux.cpp>
#endif

#if JUCE_MAC
#include <juce_core/native/juce_Files_mac.mm>
#endif
