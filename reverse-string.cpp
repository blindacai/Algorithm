// input: {'a','b','c'} or "abc"
// output: "cba"
void reverse(char* str){
    char* end = str;
    char tmp;

    if(str){
        while(*end){
            end += 1;
        }
        end -= 1;

        while(str < end){
            tmp = *str;
            *str = *end;
            *end = tmp;
            str += 1;
            end -= 1;
        }
    }
}