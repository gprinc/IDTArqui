#include <standardio.h>
//Access Denied exception handler
void handle_exc_access_denied(){
	
}

//Zero Division exception handler
void handle_exc_divide_by_0(){
	printf("[EXCEPTION 00] Division by zero exception! Program interrupted.");
}

//Overflow exception handler
void handle_exc_overflow(){
	printf("[EXCEPTION 04] Overflow exception! Program interrupted.");
}

//Invalid Operation Code exception handler
void handle_exc_invalid_opcode(){
	printf("[EXCEPTION 06] Invalid Operation Code exception! Program interrupted.");
}