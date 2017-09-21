#include<stdio.h>
int sameSuit ( int c1, int c2 ) {
return ( ( c1 & 0x30 ) == ( c2 & 0x30 ) );
}

int main() {
    int no1, no2, card1, card2;
    printf ( "Enter 1-13 for A-K numbers \n" );
    printf ( "Enter 1-4 for Hearts, Spades, Diamonds & Clubs \n" );
    printf ( "Enter the values for card1 :\n" );
    scanf ( "%d%d", &no1, &card1 );
    printf ( "Enter the values for card2 :\n" );
    scanf ( "%d%d", &no2, &card2 );
    int a = sameSuit ( card1, card2 );
    if ( a==1 )
        printf ( "The cards are of same suit.!\n" );
    else 
        printf ( "The cards are of diff suit.!\n" );
return 0;
}
