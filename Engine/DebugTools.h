/*
	http://support.microsoft.com/kb/166474
	To speed the build process, Visual C++ and the Windows Headers provide the following new defines:

	VC_EXTRALEAN
	WIN32_LEAN_AND_MEAN

	You can use them to reduce the size of the Win32 header files.
*/
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/*
	stringstream class
	it enables formatting the string buffer it has, which can be accessed as a C++ string object
*/
#include <sstream>

namespace DebugTools
{
	bool Assert(int expression,
							const char* outputMessage,
							const char* functionName,
							const char* fileName,
							unsigned int lineNumber)
	{
		if (!expression)
		{
			std::stringstream ssObject;

			//format string buffer of stringstream object
			ssObject << "ASSERTION FAILURE : ";
			ssObject << "\nFile : " << fileName;
			ssObject << "\nLine Number : " << lineNumber;
			ssObject << "\nFunction Name : " << functionName;
			ssObject << "\nDescription : " << outputMessage;

			//multi byte string to wide character string
			/*
				https://msdn.microsoft.com/en-us/library/eyktyxsx.aspx

				errno_t mbstowcs_s(size_t *pReturnValue, //	[out] The number of characters converted.
				wchar_t *wcstr,			 // [out] Address of buffer for the resulting converted wide character string.
				size_t sizeInWords,	 // [in] The size of the wcstr buffer in words.
				const char *mbstr,		 //	[in] The address of a sequence of null terminated multibyte characters.
				size_t count);				 // [in] The maximum number of wide characters to store in the wcstr buffer, not including the terminating null, or _TRUNCATE.

				If mbstowcs_s successfully converts the source string, it puts the size in wide characters of the converted string,
				including the null terminator, into *``pReturnValue (provided pReturnValue is not NULL).
				This occurs even if the wcstr argument is NULL and provides a way to determine the required buffer size.
				Note that if wcstr is NULL, count is ignored, and sizeInWords must be 0.
			*/

			/*
				figure out the bufferSize
				#1 mbstowcs
				#2 strlen
			*/
			size_t bufferSize = 0;
			mbstowcs_s(&bufferSize, 0, 0, ssObject.str().c_str(), 0);
			//unsigned int bufferSize2 = 0; bufferSize2 = strlen(ssObject.str().c_str());

			wchar_t* wcstr = 0;
			wcstr = reinterpret_cast<wchar_t*>(malloc(sizeof(WCHAR) * bufferSize));
			mbstowcs_s(0, wcstr, bufferSize, ssObject.str().c_str(), (bufferSize - 1));

			int returnValue = MessageBox(NULL, wcstr, L"ASSERT!",
																	 MB_TASKMODAL | MB_SETFOREGROUND | MB_YESNO | MB_ICONERROR);
			free(wcstr);

			//clicking yes will end this function call and break into the debugger
			if (returnValue == IDYES)
				return true;

			//clicking no will exit the program
			ExitProcess((unsigned)(-1));
		}

		//never returns false, but just to make sure compiler doesn't complain
		return false;
	}
}

//When Visual Studio runs in Debug mode, it adds either two or one of the following lines.
//#define DEBUG
//#define _DEBUG

//Code for Debug Mode only.
#if defined(DEBUG) | defined(_DEBUG)

	/*! Use this macro instead of the function to ASSERT in debug only*/
	//If you want a macro to use more than one line you must put the \ at the end of every line except the last one.
	/*
		The __FUNCTION__ is a special identifier that visual studio will replace with the current function name.  
		The same is true for __FILE__ and __LINE__.
	*/
	/*
		in DEBUG mode
		if expression equals true, do nothing.
		if expression equals false, click yes to break into debugger.
		if expression equals false, cclick no to exit the program.
	*/
	#define DEBUG_ASSERT(exp, str)																			\
	if(DebugTools::Assert((exp),(str),__FUNCTION__,__FILE__, __LINE__))	\
	{                                                                   \
			DebugBreak();																										\
	}																																		\

//Code for Release Mode.
#else

	/*
		Code blocks surrounded by # signs will only be executed, in the mode specified by the preprocessor if statements.

		This approach can benefit us in making our games retain themselves with good speed,
		as we can avoid additional checkings which don't need to be run necessarily on Release Mode.

		However, it would be redundant works for us to copy and paste code blocks surrounded by # signs wherever we want them to be.
		Better decision is to use preprocessor functions called macros.

		The ability to insert or remove code before compiling is what often makes preprocessor shine,
		despite its inability to let clients debug the code easily.
	*/

#endif