

#define ROW 9
#define COLOMN 9
#define ROWS ROW+2
#define COLOMNS COLOMN+2


void InsetRow(char row[ROWS][COLOMNS],int rows,int cols,char set);
void InsetCol(char column[ROWS][COLOMNS],int rows,int cols,char set);

void Display(char column[ROWS][COLOMNS],int rows,int cols);

