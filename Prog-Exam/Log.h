class Log
{
public:
	
	static void Write(const char*, ...);
private:

};

void Log::Write(const char* format, ...)
{
	va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
	//printf(format);
}