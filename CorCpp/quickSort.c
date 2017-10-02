#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student {
    char *name;
    int age;
} stu;

int compareChar ( void* arr, int r, int l) {
    char *a = (char*)arr;
    if ( a[l] > a[r] )
        return 1;
    return 0;
}

int compareInt ( void *arr, int r, int l ) {
    stu *a = (stu*)arr;
    if ( a[l].age > a[r].age )
        return 1;
    return 0;
}

void swapStruct ( void *a, int r, int l ) {
    stu *arr = (stu*)a;
    stu *c = arr+r;
    stu *b = arr+l;
    stu temp = *c;
    *c = *b;
    *b = temp;
}
void quicksort ( void *arr, int l, int r, int (*cmp)( void*, int, int ), void (*swap) ( void*, int, int ) ) {
    if ( l>=r )
        return;
    int left = l;
    int i;
    for ( i=l+1; i<=r; i++ )
        if ( cmp ( arr, i, l ) > 0 )
            swap ( arr, i, ++left );
    swap ( arr, l, left );
    quicksort ( arr, l, left-1, cmp, swap );
    quicksort ( arr, left+1, r, cmp, swap);
}

int compareString ( void *arr, int l, int r ) {
    stu *s = (stu*)arr;
    if ( strcmp( s[r].name, s[l].name ) > 0 ) {
        return 1;
    }
    return 0;
}


void swapString ( void *arr, int l, int r ) {
    stu *s = (stu*)arr;
    char temp[10];
    strcpy ( temp, s[l].name);
    strcpy ( s[l].name, s[r].name );
    strcpy ( s[r].name, temp );
}

void insertStuData ( stu *s ) {
    (*s).name = (char*) malloc ( sizeof(char)*10 );
    scanf ( "%s%d", (*s).name, &(*s).age );
}

int main() {
    stu structArr[3];
    int j;
    for ( j=0; j<3; j++ ) {
        printf ( "Enter name and age for stu %d:\n", j+1);
        insertStuData( &structArr[j] );
    }

    quicksort ( structArr, 0, 2, compareString, swapStruct );
    printf ( "On the basis of name, Students are:\n");
    for ( j=0; j<3; j++ ) {
        printf ( "%s %d\n", structArr[j].name, structArr[j].age );
    }
    printf ( "\n" );

    quicksort ( structArr, 0, 2, compareInt, swapStruct );
    printf ( "On the basis of age are:\n");
    for ( j=0; j<3; j++ ) {
        printf ( "%s %d\n", structArr[j].name, structArr[j].age  );
    }
    printf ( "\n" );

return 0;
}
