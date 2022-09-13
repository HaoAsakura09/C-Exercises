#include <stdio.h>

#define LEN 25

struct
{
	int number;
	char name[LEN + 1];
	int on_hand;
}part1 = { .number = 528, .name = "Disk drive", .on_hand = 10 }, 
 part2;

int main(void)
{
	// prints out the members of struct
	printf("Part1 number: %d\n", part1.number);
	printf("Part1 name: %s\n", part1.name);
	printf("Part1 on hand: %d\n\n", part1.on_hand);
	
	printf("Enter Part2 number: ");
	scanf("%d", &part2.number);		// read
	printf("Enter Part2 name: ");
	scanf("%s", &part2.name);			// read
	printf("Enter Part2 on hand: ");
	scanf("%d", &part2.on_hand);	// read
	
	printf("\nPart2 number: %d\n", part2.number); // write
	printf("Part2 name: %s\n", part2.name);				// write
	printf("Part2 on hand: %d\n", part2.on_hand);	// write
	return 0;
}
