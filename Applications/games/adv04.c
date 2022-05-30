#define NUM_OBJ 66
#define WORDSIZE 3
#define GAME_MAGIC 119
#include <stdint.h>

struct location {
  const uint8_t *text;
  uint8_t exit[6];
};

const uint8_t toomuch[] = { "I am carrying too much. " };
const uint8_t dead[] = { "I am dead.\n" };
const uint8_t stored_msg[] = { "I have stored " };
const uint8_t stored_msg2[] = { " treasures. On a scale of 0 to 100, that rates " };
const uint8_t dotnewline[] = { ".\n" };
const uint8_t newline[] = { "\n" };
const uint8_t carrying[] = { "I am carrying:\n" };
const uint8_t dashstr[] = { " - " };
const uint8_t nothing[] = { "nothing" };
const uint8_t lightout[] = { "My light has run out." };
const uint8_t lightoutin[] = { "My light runs out in " };
const uint8_t turns[] = { "turns" };
const uint8_t turn[] = { "turn" };
const uint8_t whattodo[] = { "\nTell me what to do ? " };
const uint8_t prompt[] = { "\n> " };
const uint8_t dontknow[] = { "You use word(s) I don't know! " };
const uint8_t givedirn[] = { "Give me a direction too. " };
const uint8_t darkdanger[] = { "Dangerous to move in the dark! " };
const uint8_t brokeneck[] = { "I fell down and broke my neck. " };
const uint8_t cantgo[] = { "I can't go in that direction. " };
const uint8_t dontunderstand[] = { "I don't understand your command. " };
const uint8_t notyet[] = { "I can't do that yet. " };
const uint8_t beyondpower[] = { "It is beyond my power to do that. " };
const uint8_t okmsg[] = { "O.K. " };
const uint8_t whatstr[] = { "What ? " };
const uint8_t itsdark[] = { "I can't see. It is too dark!" };
const uint8_t youare[] = { "I am in a " };
const uint8_t nonestr[] = { "none" };
const uint8_t obexit[] = { "\nObvious exits: " };
const uint8_t canalsosee[] = { "I can also see: " };
const uint8_t playagain[] = { "Do you want to play again Y/N: " };
const uint8_t invcond[] = { "INVCOND" };
const uint8_t *exitmsgptr[] = {
  (uint8_t *)"North",
  (uint8_t *)"South",
  (uint8_t *)"East",
  (uint8_t *)"West",
  (uint8_t *)"Up",
  (uint8_t *)"Down"
};



/*
 * 
 *	Game database follows below. Although linked into the same asm
 *	file to make life easier this is just "mere aggregation" for
 *	convenience, due to limits in the tool chain and the game licence
 *	not the GPL applies to the game database.
 */
const uint8_t startlamp = 255;
const uint8_t lightfill = 255;
const uint8_t startcarried = 0;
const uint8_t maxcar = 9;
const uint8_t treasure = 0;
const uint8_t treasures = 0;
const uint8_t lastloc = 25;
const uint8_t startloc = 1;


const struct location locdata[] = {
		{ 	"",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x63\x68\x61\x70\x65\x6C",
 { 9, 2, 4, 10, 0, 0 } }, 
		{ 	"\x44\x69\x6E\x67\x79\x20\x4C\x6F\x6F\x6B\x69\x6E\x67\x20\x53\x74\x61\x69\x72\x77\x65\x6C\x6C",
 { 1, 24, 3, 11, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 5, 0, 0, 2, 0, 0 } }, 
		{ 	"\x54\x75\x6E\x6E\x65\x6C",
 { 0, 0, 0, 1, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 0, 3, 7, 0, 0, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x69\x6E\x20\x4D\x65\x64\x69\x75\x6D\x20\x4D\x61\x65\x67\x65\x6E\x27\x73\x20\x4D\x61\x64\x20\x52\x6F\x6F\x6D",
 { 0, 0, 0, 8, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 0, 0, 17, 5, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 0, 1, 0, 0, 0, 0 } }, 
		{ 	"\x42\x61\x6C\x6C\x72\x6F\x6F\x6D",
 { 0, 0, 1, 0, 0, 0 } }, 
		{ 	"\x64\x75\x6E\x67\x65\x6F\x6E",
 { 0, 13, 2, 0, 0, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x41\x72\x6D\x6F\x72\x79",
 { 0, 0, 0, 13, 0, 0 } }, 
		{ 	"\x74\x6F\x72\x74\x75\x72\x65\x20\x63\x68\x61\x6D\x62\x65\x72",
 { 11, 0, 12, 0, 0, 0 } }, 
		{ 	"\x43\x68\x69\x6D\x6E\x65\x79",
 { 0, 0, 0, 0, 0, 15 } }, 
		{ 	"\x6C\x61\x72\x67\x65\x20\x66\x69\x72\x65\x70\x6C\x61\x63\x65",
 { 0, 10, 0, 0, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 0, 0, 0, 0, 3, 0 } }, 
		{ 	"\x4C\x61\x62",
 { 0, 0, 0, 7, 0, 0 } }, 
		{ 	"\x6E\x61\x72\x72\x6F\x77\x20\x70\x61\x72\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x63\x68\x69\x6D\x6E\x65\x79",
 { 0, 0, 0, 0, 0, 14 } }, 
		{ 	"\x47\x72\x61\x76\x65\x79\x61\x72\x64",
 { 0, 0, 13, 0, 0, 0 } }, 
		{ 	"\x70\x61\x72\x6C\x6F\x72",
 { 0, 0, 0, 0, 0, 2 } }, 
		{ 	"\x4A\x61\x69\x6C\x20\x43\x65\x6C\x6C",
 { 0, 0, 0, 0, 0, 0 } }, 
		{ 	"\x2A\x49\x27\x6D\x20\x6F\x6E\x20\x61\x20\x6C\x65\x64\x67\x65",
 { 0, 9, 0, 0, 0, 0 } }, 
		{ 	"\x68\x69\x64\x64\x65\x6E\x20\x56\x4F\x4F\x44\x4F\x4F\x20\x72\x6F\x6F\x6D",
 { 0, 8, 0, 0, 0, 0 } }, 
		{ 	"\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x20\x63\x61\x73\x74\x6C\x65",
 { 2, 0, 0, 0, 0, 0 } }, 
		{ 	"\x6C\x6F\x74\x20\x6F\x66\x20\x54\x52\x4F\x55\x42\x4C\x45\x21",
 { 0, 0, 0, 0, 0, 0 } }, 
};
const uint8_t objinit[] = {
	4,
	0,
	8,
	5,
	2,
	3,
	0,
	12,
	2,
	0,
	9,
	0,
	15,
	0,
	0,
	19,
	7,
	1,
	6,
	0,
	10,
	14,
	13,
	0,
	4,
	0,
	17,
	0,
	0,
	0,
	8,
	0,
	16,
	12,
	0,
	18,
	17,
	0,
	17,
	11,
	0,
	0,
	0,
	15,
	22,
	0,
	14,
	0,
	0,
	19,
	0,
	0,
	0,
	20,
	0,
	0,
	11,
	12,
	21,
	0,
	21,
	8,
	8,
	0,
	23,
	0,
};


const uint8_t *objtext[] = {
	"\x42\x6C\x6F\x6F\x64\x79\x20\x4B\x6E\x69\x66\x65",
	"\x4C\x65\x64\x67\x65",
	"\x50\x6C\x61\x71\x75\x65",
	"\x41\x6E\x69\x6D\x61\x6C\x20\x68\x65\x61\x64\x73",
	"\x42\x72\x6F\x6B\x65\x6E\x20\x67\x6C\x61\x73\x73",
	"\x42\x69\x67\x20\x6B\x65\x74\x74\x6C\x65",
	"\x44\x61\x72\x6B\x20\x68\x6F\x6C\x65",
	"\x53\x68\x69\x65\x6C\x64",
	"\x53\x74\x61\x69\x72\x73",
	"\x42\x72\x69\x67\x68\x74\x6C\x79\x20\x67\x6C\x6F\x77\x69\x6E\x67\x20\x69\x64\x6F\x6C",
	"\x4F\x70\x65\x6E\x20\x57\x69\x6E\x64\x6F\x77",
	"\x44\x61\x72\x6B\x20\x43\x68\x69\x6D\x6E\x65\x79",
	"\x43\x6C\x6F\x73\x65\x64\x20\x46\x6C\x75\x65",
	"\x4F\x70\x65\x6E\x20\x46\x6C\x75\x65",
	"\x46\x6F\x75\x72\x20\x6C\x65\x61\x66\x20\x63\x6C\x6F\x76\x65\x72",
	"\x47\x72\x41\x76\x65\x73",
	"\x43\x61\x73\x74\x20\x69\x72\x6F\x6E\x20\x70\x6F\x74",
	"\x43\x6C\x6F\x73\x65\x64\x20\x43\x6F\x66\x66\x69\x6E",
	"\x43\x72\x79\x73\x74\x61\x6C\x20\x42\x61\x6C\x6C",
	"\x43\x6C\x6F\x73\x65\x64\x20\x57\x69\x6E\x64\x6F\x77",
	"\x4C\x61\x72\x67\x65\x20\x66\x69\x72\x65\x70\x6C\x61\x63\x65",
	"\x53\x6F\x6F\x74",
	"\x54\x69\x6E\x79\x20\x6F\x70\x65\x6E\x20\x64\x6F\x6F\x72",
	"\x53\x70\x69\x72\x69\x74\x20\x4D\x65\x64\x69\x75\x6D",
	"\x4D\x61\x73\x73\x69\x76\x65\x20\x73\x74\x6F\x6E\x65\x20\x64\x6F\x6F\x72\x20\x77\x69\x74\x68\x20\x61\x20\x53\x41\x50\x50\x48\x49\x52\x45\x20\x73\x65\x74\x20\x69\x6E\x74\x6F\x20\x69\x74",
	"\x53\x61\x70\x70\x68\x69\x72\x65\x20\x72\x69\x6E\x67",
	"\x4A\x75\x2D\x4A\x75\x20\x62\x61\x67",
	"\x4F\x70\x65\x6E\x20\x43\x6F\x66\x66\x69\x6E",
	"\x53\x6C\x69\x63\x6B\x20\x63\x68\x75\x74\x65\x20\x6C\x65\x61\x64\x69\x6E\x67\x20\x64\x6F\x77\x6E\x77\x61\x72\x64",
	"\x4A\x75\x2D\x4A\x75\x20\x6D\x61\x6E",
	"\x53\x6C\x69\x70\x70\x65\x72\x79\x20\x63\x68\x75\x74\x65\x20\x6C\x65\x61\x64\x69\x6E\x67\x20\x75\x70",
	"\x57\x69\x64\x65\x20\x63\x72\x61\x63\x6B\x20\x69\x6E\x20\x74\x68\x65\x20\x77\x61\x6C\x6C",
	"\x52\x61\x62\x62\x69\x74\x27\x73\x20\x66\x6F\x6F\x74",
	"\x44\x75\x6C\x6C\x20\x26\x20\x62\x72\x6F\x6B\x65\x6E\x20\x73\x77\x6F\x72\x64",
	"\x4F\x70\x65\x6E\x20\x53\x41\x66\x65",
	"\x53\x74\x75\x63\x6B\x20\x43\x68\x69\x6D\x6E\x65\x79\x20\x53\x77\x65\x65\x70",
	"\x43\x68\x65\x6D\x20\x74\x75\x62\x65\x73",
	"\x43\x6C\x6F\x73\x65\x64\x20\x53\x41\x66\x65",
	"\x4C\x61\x62\x65\x6C\x65\x64\x20\x63\x68\x65\x6D\x69\x63\x61\x6C\x73",
	"\x50\x6F\x63\x6B\x65\x74\x20\x53\x68\x6F\x76\x65\x6C",
	"\x4D\x69\x78\x65\x64\x20\x43\x68\x65\x6D\x69\x63\x61\x6C\x73",
	"\x57\x69\x64\x65\x20\x6F\x70\x65\x6E\x20\x64\x6F\x6F\x72",
	"\x4E\x61\x69\x6C\x73",
	"\x44\x75\x73\x74\x79\x20\x49\x64\x6F\x6C",
	"\x44\x6F\x6C\x6C",
	"\x57\x6F\x6F\x64\x65\x6E\x20\x62\x6F\x61\x72\x64\x73",
	"\x57\x6F\x6F\x64\x20\x62\x6F\x61\x72\x64\x73\x20\x6E\x61\x69\x6C\x65\x64\x20\x74\x6F\x20\x63\x68\x69\x6D\x6E\x65\x79\x20\x77\x61\x6C\x6C",
	"\x41\x6E\x74\x69\x71\x75\x65\x20\x68\x61\x6D\x6D\x65\x72",
	"\x47\x72\x41\x74\x69\x6E\x67",
	"\x52\x75\x73\x74\x69\x6E\x67\x20\x53\x41\x57",
	"\x42\x75\x74\x74\x6F\x6E\x20\x69\x6E\x20\x74\x68\x65\x20\x77\x61\x6C\x6C",
	"\x50\x61\x70\x65\x72",
	"\x56\x6F\x6F\x64\x6F\x6F\x20\x62\x6F\x6F\x6B",
	"\x4A\x75\x2D\x4A\x75\x20\x6D\x61\x6E\x20\x73\x74\x61\x74\x75\x65",
	"\x53\x74\x69\x63\x6B",
	"\x4F\x70\x65\x6E\x20\x77\x61\x6C\x6C",
	"\x4F\x70\x65\x6E\x20\x6A\x61\x69\x6C\x20\x63\x65\x6C\x6C",
	"\x4B\x6E\x69\x67\x68\x74\x27\x73\x20\x53\x75\x69\x74\x20\x6F\x66\x20\x41\x72\x6D\x6F\x72",
	"\x43\x6C\x6F\x73\x65\x64\x20\x63\x65\x6C\x6C\x20\x64\x6F\x6F\x72",
	"\x42\x72\x6F\x6B\x65\x6E\x20\x67\x72\x61\x74\x69\x6E\x67",
	"\x41\x64\x76\x65\x72\x74\x69\x73\x69\x6E\x67\x20\x6C\x65\x61\x66\x6C\x65\x74",
	"\x43\x72\x61\x63\x6B\x20\x69\x6E\x20\x74\x68\x65\x20\x77\x61\x6C\x6C",
	"\x48\x6F\x6C\x65\x20\x69\x6E\x20\x74\x68\x65\x20\x77\x61\x6C\x6C",
	"\x50\x69\x65\x63\x65\x73\x20\x6F\x66\x20\x72\x6F\x63\x6B",
	"\x50\x61\x67\x65\x20\x74\x6F\x72\x6E\x20\x66\x72\x6F\x6D\x20\x61\x20\x62\x6F\x6F\x6B",
	"\x53\x6D\x69\x6C\x69\x6E\x67\x20\x43\x6F\x75\x6E\x74\x20\x43\x72\x69\x73\x74\x6F",
};
const uint8_t *msgptr[] = {
	"",
	"\x43\x6F\x75\x6E\x74\x20\x43\x72\x69\x73\x74\x6F\x27\x73\x20\x62\x65\x65\x6E\x20\x43\x55\x52\x53\x45\x44\x21\x20\x54\x68\x65\x72\x65\x27\x73\x20\x6F\x6E\x65\x20\x77\x61\x79\x20\x66\x6F\x72\x20\x68\x69\x6D\x20\x74\x6F\x20\x66\x6C\x65\x65\x21\x0A\x46\x69\x6E\x64\x20\x69\x74\x2C\x20\x61\x6E\x64\x20\x68\x65\x27\x6C\x6C\x20\x67\x6F\x20\x46\x52\x45\x45\x21",
	"\x49\x74\x20\x62\x65\x6C\x6F\x6E\x67\x73\x20\x74\x6F\x20\x74\x68\x65\x20\x6D\x65\x64\x69\x75\x6D",
	"\x53\x70\x69\x72\x69\x74\x20\x76\x69\x62\x72\x61\x74\x69\x6F\x6E\x73\x20\x64\x72\x69\x76\x65\x20\x6D\x65\x20\x66\x72\x6F\x6D\x20\x72\x6F\x6F\x6D\x2E",
	"\x50\x72\x69\x6E\x74\x73\x20\x74\x6F\x6F\x20\x73\x6D\x61\x6C\x6C\x20\x66\x6F\x72\x20\x74\x68\x65\x20\x75\x6E\x61\x69\x64\x65\x64\x20\x65\x79\x65\x2E",
	"\x49\x20\x63\x61\x6E\x27\x74\x20\x64\x6F\x20\x74\x68\x61\x74",
	"\x4E\x6F\x74\x68\x69\x6E\x67\x20\x68\x61\x70\x70\x65\x6E\x65\x64",
	"\x57\x69\x6E\x64\x6F\x77\x73\x20\x6F\x70\x65\x6E",
	"\x57\x69\x6E\x64\x6F\x77\x20\x6A\x75\x73\x74\x20\x73\x6C\x41\x6D\x6D\x65\x64\x20\x73\x68\x75\x74",
	"\x46\x6F\x72\x20\x61\x20\x72\x65\x61\x64\x69\x6E\x67\x20\x6A\x75\x73\x74\x20\x22\x53\x55\x4D\x4D\x4F\x4E\x20\x4D\x45\x44\x49\x55\x4D\x20\x4D\x41\x45\x47\x45\x4E\x22\x20\x74\x6F\x64\x61\x79\x21\x21",
	"\x49\x20\x73\x65\x65\x20\x6E\x6F\x74\x68\x69\x6E\x67\x20\x76\x65\x72\x79\x20\x73\x70\x65\x63\x69\x61\x6C\x2E",
	"\x50\x68\x6F\x73\x70\x68\x6F\x72\x65\x73\x63\x65\x6E\x74\x20\x6C\x65\x74\x74\x65\x72\x73\x20\x61\x72\x65\x20\x76\x65\x72\x79\x20\x68\x61\x72\x64\x20\x74\x6F\x20\x72\x65\x61\x64\x20\x69\x6E\x20\x62\x72\x69\x67\x68\x74\x20\x6C\x69\x67\x68\x74\x21",
	"\x41\x6D\x6F\x6E\x67\x73\x74\x20\x74\x68\x65\x20\x47\x52\x41\x56\x45\x53\x20\x69\x73\x20\x61\x20\x66\x6F\x75\x72\x20\x6C\x65\x61\x66\x20\x63\x6C\x6F\x76\x65\x72\x2E",
	"\x52\x61\x76\x65\x6E\x20\x63\x72\x79\x73\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x6F\x75\x74\x73\x69\x64\x65",
	"\x4F\x6E\x65\x20\x6F\x66\x20\x74\x68\x65\x20\x74\x65\x73\x74\x20\x74\x75\x62\x65\x73\x20\x45\x58\x50\x4C\x4F\x44\x45\x44\x21",
	"\x54\x68\x69\x73\x20\x67\x6C\x61\x73\x73\x20\x63\x61\x6E\x27\x74\x20\x62\x65\x20\x62\x72\x6F\x6B\x65\x6E",
	"\x2E",
	"\x54\x68\x65\x79\x20\x61\x70\x70\x65\x61\x72\x20\x74\x6F\x20\x62\x65\x20\x6D\x69\x78\x61\x62\x6C\x65\x2E",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x77\x72\x69\x74\x74\x65\x6E\x20\x74\x68\x65\x72\x65",
	"\x41\x20\x73\x65\x70\x75\x6C\x63\x68\x72\x61\x6C\x20\x76\x6F\x69\x63\x65\x20\x73\x61\x79\x73\x3A",
	"\x4F\x4B",
	"\x53\x61\x66\x65\x27\x73\x20\x63\x6F\x6D\x62\x69\x6E\x61\x74\x69\x6F\x6E\x20\x6C\x6F\x63\x6B\x20\x69\x73\x20\x6E\x75\x6D\x62\x65\x72\x65\x64\x20\x66\x72\x6F\x6D\x20\x33\x33\x20\x74\x6F\x20\x33\x38\x2E",
	"\x52\x69\x6E\x67\x20\x67\x6C\x6F\x77\x73\x20\x62\x72\x69\x65\x66\x6C\x79\x20\x26\x20\x64\x6F\x6F\x72\x20\x76\x61\x6E\x69\x73\x68\x65\x73",
	"\x4F\x55\x43\x48",
	"\x41\x20\x73\x69\x67\x6E\x20\x68\x65\x72\x65\x20\x73\x61\x79\x73\x3A",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x6D\x61\x6E\x20\x68\x65\x72\x65",
	"\x57\x65\x61\x72\x69\x6E\x67\x20\x61\x20\x73\x61\x70\x70\x68\x69\x72\x65\x20\x72\x69\x6E\x67",
	"\x49\x20\x73\x6C\x69\x64\x65\x20\x62\x61\x63\x6B\x20\x64\x6F\x77\x6E",
	"\x41\x20\x62\x65\x61\x6D\x20\x6F\x66\x20\x6C\x69\x67\x68\x74\x20\x73\x68\x69\x6E\x65\x73\x20\x6F\x6E\x20\x67\x72\x61\x76\x65",
	"\x50\x69\x6E\x73\x20\x66\x61\x6C\x6C\x20\x6F\x75\x74\x20\x6F\x66\x20\x64\x6F\x6C\x6C",
	"\x50\x6C\x61\x71\x75\x65\x20\x73\x61\x79\x73\x3A\x20\x22\x73\x61\x66\x65\x20\x2D\x2D\x3E\x20\x33\x38\x20\x33\x33\x22",
	"\x54\x68\x69\x73\x20\x67\x72\x41\x76\x65\x20\x72\x65\x73\x65\x72\x76\x65\x64\x20\x66\x6F\x72\x20\x79\x6F\x75\x21",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x43\x4C\x41\x50\x20\x4F\x46\x20\x54\x48\x55\x4E\x44\x45\x52\x21",
	"\x4A\x75\x2D\x4A\x75\x20\x6D\x61\x6E\x20\x73\x61\x79\x73\x3A\x22\x4D\x79\x20\x62\x61\x67\x20\x69\x73\x20\x6E\x6F\x77\x20\x79\x6F\x75\x72\x73\x21\x20\x49\x74\x73\x20\x6D\x61\x67\x69\x63\x20\x77\x69\x6C\x6C\x20\x68\x65\x6C\x70\x20\x79\x6F\x75\x0A\x20\x2D\x43\x52\x41\x43\x4B\x2D\x20\x74\x68\x65\x20\x63\x75\x72\x73\x65\x21\x22\x2E",
	"\x48\x55\x52\x52\x41\x48\x21\x20\x4C\x6F\x6F\x6B\x20\x77\x68\x6F\x20\x69\x73\x20\x69\x6E\x20\x74\x68\x65\x20\x72\x6F\x6F\x6D\x21",
	"\x49\x27\x6D\x20\x6E\x6F\x77\x20\x34\x20\x66\x65\x65\x74\x20\x74\x61\x6C\x6C\x21",
	"\x49\x74\x27\x73\x20\x6D\x75\x63\x68\x20\x74\x6F\x20\x68\x65\x61\x76\x79\x20\x74\x6F\x20\x4C\x49\x46\x54\x21",
	"\x49\x27\x6D\x20\x74\x6F\x6F\x20\x62\x69\x67",
	"\x59\x6F\x75\x20\x73\x74\x61\x72\x74\x6C\x65\x64\x20\x6D\x65\x64\x69\x75\x6D\x20\x26\x20\x73\x68\x65\x20\x76\x61\x6E\x69\x73\x68\x65\x64",
	"\x4F\x6E\x20\x77\x68\x61\x74\x3F",
	"\x4D\x61\x69\x64\x20\x63\x68\x61\x73\x65\x64\x20\x6D\x65\x20\x77\x69\x74\x68\x20\x62\x72\x6F\x6F\x6D\x20\x66\x6F\x72\x20\x74\x72\x61\x63\x6B\x69\x6E\x67\x20\x73\x6F\x6F\x74\x20\x74\x68\x72\x6F\x75\x67\x68\x20\x74\x68\x65\x20\x42\x61\x6C\x6C\x2D\x0A\x72\x6F\x6F\x6D\x2E\x20\x49\x20\x77\x6F\x6E\x64\x65\x72\x20\x77\x68\x65\x72\x65\x20\x49\x20\x61\x6D\x3F",
	"\x53\x77\x65\x65\x70\x20\x70\x6F\x70\x73\x20\x6F\x75\x74\x2C\x20\x74\x68\x61\x6E\x6B\x73\x20\x6D\x65\x2C\x20\x68\x61\x6E\x64\x73\x20\x6D\x65\x20\x61\x20\x70\x69\x65\x63\x65\x20\x6F\x66\x20\x70\x61\x70\x65\x72\x20\x74\x68\x65\x6E\x0A\x76\x61\x6E\x69\x73\x68\x65\x73\x21",
	"\x41\x73\x20\x49\x20\x64\x75\x73\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x49\x64\x6F\x6C\x20\x69\x74\x20\x62\x65\x67\x69\x6E\x73\x20\x74\x6F\x20\x67\x6C\x6F\x77\x21",
	"\x48\x65\x27\x73\x20\x77\x65\x61\x72\x69\x6E\x67\x20\x61\x20\x72\x61\x62\x62\x69\x74\x27\x73\x20\x66\x6F\x6F\x74",
	"\x2E",
	"\x48\x45\x4C\x50\x20\x4D\x45\x2C\x20\x49\x27\x6D\x20\x73\x74\x75\x63\x6B\x21",
	"\x4C\x75\x63\x6B\x20\x77\x61\x73\x6E\x27\x74\x20\x77\x69\x74\x68\x20\x6D\x65\x21",
	"\x44\x6F\x6C\x6C\x20\x6C\x6F\x6F\x6B\x73\x20\x6C\x69\x6B\x65\x20\x43\x6F\x75\x6E\x74\x20\x43\x72\x69\x73\x74\x6F\x2E\x20\x54\x68\x65\x72\x65\x27\x72\x65\x20\x70\x69\x6E\x73\x20\x69\x6E\x20\x69\x74\x21",
	"\x2E",
	"\x42\x69\x72\x64\x20\x73\x61\x79\x73\x3A\x20\x22\x61\x73\x6B\x20\x66\x6F\x72\x20\x41\x44\x56\x45\x4E\x54\x55\x52\x45\x20\x35\x2C\x20\x2D\x54\x48\x45\x20\x43\x4F\x55\x4E\x54\x2D\x20\x61\x74\x20\x79\x6F\x75\x72\x0A\x20\x66\x61\x76\x6F\x72\x69\x74\x65\x20\x63\x6F\x6D\x70\x75\x74\x65\x72\x20\x64\x65\x61\x6C\x65\x72\x2E\x20\x49\x74\x20\x77\x69\x6C\x6C\x20\x62\x65\x20\x4C\x4F\x56\x45\x20\x41\x54\x20\x46\x49\x52\x53\x54\x20\x42\x59\x54\x45\x21\x22\x0A",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x73\x6F\x6D\x65\x20\x73\x6F\x75\x70\x20\x68\x65\x72\x65\x2E",
	"\x49\x20\x73\x65\x65\x20\x61\x20\x68\x6F\x6C\x65\x20\x75\x6E\x64\x65\x72\x20\x69\x74\x21",
	"\x4E\x61\x69\x6C\x73\x20\x77\x65\x72\x65\x20\x72\x75\x73\x74\x65\x64\x20\x62\x75\x74\x20\x49\x20\x67\x6F\x74\x20\x74\x68\x65\x6D\x20\x6F\x75\x74\x2E",
	"\x49\x74\x27\x73\x20\x68\x41\x72\x64\x20\x77\x6F\x72\x6B\x20\x62\x75\x74\x20\x69\x74\x20\x73\x65\x65\x6D\x73\x20\x74\x6F\x20\x62\x65\x20\x63\x6F\x6D\x69\x6E\x67\x20\x6C\x6F\x6F\x73\x65",
	"\x49\x20\x68\x65\x61\x72\x20\x73\x74\x72\x61\x6E\x67\x65\x20\x73\x6F\x75\x6E\x64\x73\x2C\x20\x61\x73\x20\x69\x66\x20\x73\x6F\x6D\x65\x6F\x6E\x65\x20\x77\x65\x72\x65\x20\x6D\x6F\x61\x6E\x69\x6E\x67\x2E",
	"\x49\x27\x76\x65\x20\x67\x6F\x74\x20\x69\x74\x21",
	"\x48\x65\x61\x76\x79\x20\x64\x75\x74\x79\x20\x65\x78\x68\x61\x75\x73\x74\x20\x66\x61\x6E\x20\x63\x6F\x6D\x65\x73\x20\x6F\x6E\x20\x26\x20\x73\x75\x63\x6B\x73\x20\x6D\x65\x20\x75\x70\x21",
	"\x2E",
	"\x73\x61\x79\x73\x3A\x20\x22\x53\x41\x59\x20\x5A\x41\x50\x20\x20\x20\x74\x6F\x20\x72\x65\x73\x74\x6F\x72\x65\x20\x73\x6F\x6D\x65\x6F\x6E\x65\x20\x63\x68\x61\x6E\x67\x65\x64\x20\x74\x6F\x20\x73\x74\x6F\x6E\x65\x21\x22",
	"\x53\x74\x61\x74\x75\x65\x20\x69\x73\x20\x6D\x61\x64\x65\x20\x6F\x66\x20\x73\x74\x6F\x6E\x65",
	"\x49\x20\x68\x65\x61\x72\x20\x6E\x6F\x74\x68\x69\x6E\x67\x2E",
	"\x77\x6F\x6E\x27\x74\x20\x62\x75\x64\x67\x65\x21",
	"\x49\x27\x6C\x6C\x20\x6E\x65\x65\x64\x20\x73\x6F\x6D\x65\x74\x68\x69\x6E\x67\x20\x74\x6F\x20\x70\x72\x79\x20\x69\x74\x20\x6F\x66\x66\x20\x74\x68\x65\x20\x77\x61\x6C\x6C\x21",
	"\x49\x74\x27\x73\x20\x61\x20\x62\x6F\x6F\x6B\x20\x6F\x6E\x20\x72\x65\x6D\x6F\x76\x69\x6E\x67\x20\x63\x75\x72\x73\x65\x73\x2E\x20\x53\x61\x79\x73\x3A\x20\x22\x57\x69\x74\x68\x20\x6B\x6E\x69\x66\x65\x20\x69\x6E\x20\x68\x61\x6E\x64\x20\x79\x6F\x75\x0A\x74\x61\x6B\x65\x20\x61\x20\x73\x74\x61\x6E\x64\x2E\x20\x43\x69\x72\x63\x6C\x65\x20\x63\x6F\x66\x66\x69\x6E\x20\x61\x6E\x64\x2E\x2E\x2E\x22\x20\x54\x68\x65\x20\x72\x65\x73\x74\x20\x6F\x66\x20\x74\x68\x65\x20\x70\x61\x67\x65\x20\x69\x73\x0A\x6D\x69\x73\x73\x69\x6E\x67\x21\x21\x21",
	"\x49\x74\x73\x20\x76\x65\x72\x79\x20\x64\x61\x72\x6B\x2C\x20\x74\x68\x65\x20\x6F\x6E\x6C\x79\x20\x6C\x69\x67\x68\x74\x20\x69\x73\x20\x66\x72\x6F\x6D\x20\x74\x68\x65\x20\x69\x64\x6F\x6C\x2E",
	"\x54\x68\x61\x74\x27\x73\x20\x69\x6C\x6C\x65\x67\x61\x6C\x21",
	"\x44\x6F\x75\x62\x6C\x65\x20\x62\x75\x62\x62\x6C\x65\x20\x74\x6F\x69\x6C\x20\x26\x20\x74\x72\x6F\x75\x62\x6C\x65\x20\x74\x68\x65\x20\x65\x6E\x63\x41\x6E\x74\x41\x74\x69\x6F\x6E\x73\x20\x41\x72\x65\x20\x41\x62\x6F\x75\x74\x20\x74\x6F\x20\x70\x65\x41\x6B\x21",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x6E\x20\x61\x6E\x74\x69\x71\x75\x65\x20\x68\x61\x6D\x6D\x65\x72\x20\x68\x65\x72\x65",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x43\x6C\x61\x70\x20\x6F\x66\x20\x54\x68\x75\x6E\x64\x65\x72\x20\x26\x20\x74\x68\x65\x6E\x20\x73\x75\x64\x64\x65\x6E\x6C\x79\x20\x74\x68\x65\x20\x73\x74\x6F\x6E\x65\x20\x73\x74\x61\x74\x75\x65\x0A\x62\x65\x67\x69\x6E\x73\x20\x74\x6F\x20\x63\x72\x61\x63\x6B\x2E\x20\x49\x20\x6D\x61\x79\x20\x62\x65\x20\x69\x6E\x20\x74\x72\x6F\x75\x62\x6C\x65\x20\x6E\x6F\x77\x2C\x20\x74\x68\x65\x72\x65\x27\x73\x20\x73\x6F\x6D\x65\x6F\x6E\x65\x20\x69\x6E\x0A\x74\x68\x65\x20\x72\x6F\x6F\x6D\x20\x77\x69\x74\x68\x20\x6D\x65\x21",
	"\x4C\x6F\x6F\x6B\x73\x20\x61\x6C\x6D\x6F\x73\x74\x20\x6C\x69\x6B\x65\x20\x6C\x65\x6D\x6F\x6E\x61\x64\x65\x2E\x20\x59\x75\x6D\x6D\x79\x21",
	"\x59\x6F\x75\x27\x76\x65\x20\x62\x65\x65\x6E\x20\x74\x75\x72\x6E\x65\x64\x20\x69\x6E\x74\x6F\x20\x61\x20\x62\x72\x6F\x6F\x6D\x73\x74\x69\x63\x6B\x20\x26\x20\x61\x20\x77\x69\x74\x63\x68\x20\x72\x69\x64\x65\x73\x20\x6F\x66\x66\x20\x6F\x6E\x20\x79\x6F\x75\x21",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x77\x69\x74\x63\x68\x27\x73\x20\x62\x72\x65\x77\x20\x74\x68\x65\x72\x65",
	"\x43\x65\x6C\x6C\x20\x64\x6F\x6F\x72\x20\x73\x6C\x61\x6D\x73\x20\x73\x68\x75\x74",
	"\x59\x6F\x75\x27\x76\x65\x20\x62\x65\x65\x6E\x20\x73\x70\x72\x75\x6E\x67",
	"\x2E\x2E\x2E\x77\x61\x76\x65\x20\x74\x68\x65\x20\x73\x74\x69\x63\x6B\x20\x61\x6E\x64\x20\x68\x6F\x6C\x64\x20\x74\x68\x65\x20\x6C\x61\x6D\x70\x20\x61\x6E\x64\x20\x64\x6F\x6E\x27\x74\x20\x66\x6F\x72\x67\x65\x74\x20\x74\x6F\x20\x79\x65\x6C\x6C\x0A\x22\x43\x48\x41\x4E\x54\x22\x21\x20\x4F\x68\x20\x79\x65\x73\x2C\x20\x74\x6F\x20\x68\x65\x6C\x70\x20\x69\x74\x20\x73\x75\x63\x63\x65\x65\x64\x2C\x20\x61\x20\x64\x6F\x6C\x6C\x20\x79\x6F\x75\x27\x6C\x6C\x20\x6E\x65\x65\x64\x2E\x2E\x2E",
	"\x57\x65\x6C\x63\x6F\x6D\x65\x20\x74\x6F\x20\x41\x44\x56\x45\x4E\x54\x55\x52\x45\x3A\x34\x2C\x20\x22\x56\x4F\x4F\x44\x4F\x4F\x20\x43\x41\x53\x54\x4C\x45\x22\x20\x62\x79\x20\x41\x6C\x65\x78\x69\x73\x20\x41\x44\x41\x4D\x53\x2E\x0A\x44\x65\x64\x69\x63\x61\x74\x65\x64\x20\x74\x6F\x20\x61\x6C\x6C\x20\x4D\x4F\x4D\x53\x21",
	"\x68\x6F\x77\x3F",
	"\x49\x74\x20\x61\x70\x70\x65\x61\x72\x73\x20\x73\x74\x75\x63\x6B\x20\x74\x6F\x20\x74\x68\x65\x20\x66\x6C\x6F\x6F\x72\x21",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x6E\x6F\x20\x72\x6F\x6F\x6D\x20\x69\x6E\x20\x74\x68\x65\x72\x65\x20\x66\x6F\x72\x20\x6D\x65\x21",
	"\x4D\x79\x20\x69\x64\x6F\x6C\x20\x61\x63\x74\x65\x64\x20\x73\x74\x72\x61\x6E\x67\x65",
	"\x49\x27\x76\x65\x20\x6E\x6F\x20\x63\x6F\x6E\x74\x61\x69\x6E\x65\x72\x2E",
	"\x53\x6F\x6D\x65\x20\x64\x75\x73\x74\x20\x66\x65\x6C\x6C\x20\x6F\x66\x66\x20\x69\x74\x20\x61\x6E\x64\x20\x69\x74\x20\x67\x6C\x6F\x77\x65\x64\x20\x62\x72\x69\x65\x66\x6C\x79\x2E",
	"\x49\x74\x73\x20\x76\x65\x72\x79\x20\x66\x61\x69\x6E\x74\x2E",
	"\x49\x74\x73\x20\x6D\x75\x63\x68\x20\x6C\x6F\x75\x64\x65\x72\x20\x75\x70\x20\x68\x65\x72\x65\x2E",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x62\x6F\x6F\x6B\x20\x74\x68\x65\x72\x65\x2E",
	"\x54\x68\x65\x72\x65\x27\x73\x20\x61\x20\x73\x74\x69\x63\x6B\x20\x74\x68\x65\x72\x65\x2E",
	"\x42\x6F\x79\x20\x69\x74\x20\x6C\x6F\x6F\x6B\x73\x20\x64\x75\x73\x74\x79\x2E",
	"\x49\x74\x73\x20\x67\x6C\x6F\x77\x69\x6E\x67\x2E",
	"\x53\x74\x72\x61\x6E\x67\x65\x20\x68\x6F\x62\x62\x79\x20\x79\x6F\x75\x20\x68\x61\x76\x65",
	"\x43\x68\x65\x63\x6B\x20\x6F\x75\x74\x20\x74\x68\x65\x20\x66\x69\x72\x65\x70\x6C\x61\x63\x65\x2E",
	"\x49\x74\x73\x20\x65\x6D\x70\x74\x79\x2E",
	"\x49\x20\x68\x65\x61\x72\x20\x73\x6F\x6D\x65\x6F\x6E\x65\x20\x6D\x75\x6D\x62\x6C\x69\x6E\x67\x2E",
	"\x2E",
	"\x53\x61\x77\x20\x67\x72\x61\x74\x69\x6E\x67\x21",
	"\x49\x20\x68\x61\x76\x65\x6E\x27\x74\x20\x67\x6F\x74\x20\x61\x20\x6B\x6E\x69\x66\x65\x21",
	"\x49\x6E\x73\x63\x72\x69\x70\x74\x69\x6F\x6E\x20\x6F\x6E\x20\x72\x69\x6E\x67\x20\x73\x61\x79\x73\x3A\x20\x22\x57\x41\x56\x45\x20\x4D\x45\x21\x22",
	"\x4D\x65\x64\x69\x75\x6D\x20\x61\x70\x70\x65\x61\x72\x73\x2C\x20\x73\x61\x79\x73\x3A\x20\x22\x4B\x65\x65\x70\x20\x61\x20\x67\x6F\x6F\x64\x20\x6C\x75\x63\x6B\x20\x63\x68\x61\x72\x6D\x20\x6F\x6E\x20\x79\x6F\x75\x20\x26\x20\x79\x6F\x75\x72\x0A\x66\x72\x69\x65\x6E\x64\x2E\x20\x49\x20\x61\x6C\x73\x6F\x20\x73\x65\x65\x20\x61\x20\x2D\x6D\x6F\x76\x69\x6E\x67\x2D\x20\x62\x61\x67\x20\x68\x65\x6C\x70\x69\x6E\x67\x20\x79\x6F\x75\x20\x74\x68\x72\x6F\x75\x67\x68\x20\x61\x20\x74\x69\x67\x68\x74\x0A\x73\x71\x75\x65\x65\x7A\x65\x21\x22",
	"\x49\x74\x20\x77\x69\x6C\x6C\x20\x74\x61\x6B\x65\x20\x73\x6F\x6D\x65\x20\x73\x74\x72\x6F\x6E\x67\x20\x6D\x61\x67\x69\x63\x20\x74\x6F\x20\x67\x65\x74\x20\x6D\x65\x20\x74\x68\x72\x6F\x75\x67\x68\x20\x74\x68\x61\x74\x21",
	"\x55\x73\x65\x20\x61\x20\x6E\x75\x6D\x62\x65\x72\x21",
	"\x4B\x6E\x69\x66\x65\x20\x6D\x61\x64\x65\x20\x6E\x6F\x20\x69\x6D\x70\x72\x65\x73\x73\x69\x6F\x6E\x20\x6F\x6E\x20\x69\x74\x21",
};


const uint8_t status[] = {
	132, 25, 
	2, 10, 
	13, 
	181, 
	4, 9, 2, 10, 12, 14, 0, 10, 0, 19, 
	8, 72, 
	176, 
	7, 9, 13, 19, 0, 10, 0, 19, 
	72, 
	136, 45, 
	4, 19, 14, 14, 
	28, 
	143, 30, 
	3, 36, 6, 7, 0, 25, 
	54, 64, 14, 73, 
	193, 
	24, 31, 
	136, 30, 
	3, 36, 1, 7, 
	14, 
	169, 
	4, 15, 8, 15, 
	57, 76, 
	141, 50, 
	1, 21, 0, 11, 4, 10, 
	40, 54, 
	169, 
	4, 3, 8, 15, 
	57, 76, 
	168, 
	4, 18, 13, 35, 
	104, 
	136, 35, 
	4, 14, 13, 35, 
	104, 
	136, 35, 
	4, 15, 13, 35, 
	104, 
	165, 
	4, 25, 
	46, 63, 
	169, 
	9, 7, 0, 7, 
	125, 58, 
	133, 7, 
	1, 43, 
	129, 131, 
	132, 35, 
	3, 29, 
	141, 
};
const uint8_t actions[] = {
	4, 10, 52, 
	2, 35, 
	111, 
	9, 10, 20, 
	3, 59, 0, 59, 
	20, 52, 
	23, 24, 44, 
	4, 8, 14, 31, 3, 26, 0, 31, 0, 61, 
	32, 88, 88, 72, 
	4, 38, 67, 
	6, 14, 
	5, 
	15, 1, 67, 
	2, 56, 5, 14, 0, 21, 
	70, 122, 54, 64, 
	4, 42, 25, 
	3, 2, 
	18, 
	0, 10, 10, 
	66, 
	4, 32, 15, 
	2, 19, 
	15, 
	13, 29, 11, 
	2, 5, 5, 6, 0, 6, 
	53, 20, 
	5, 10, 22, 
	2, 18, 
	19, 2, 
	8, 10, 16, 
	2, 14, 0, 14, 
	52, 
	10, 42, 20, 
	2, 15, 14, 14, 
	12, 24, 31, 
	13, 10, 16, 
	14, 14, 4, 19, 0, 14, 
	52, 20, 
	9, 42, 20, 
	2, 15, 13, 14, 
	24, 31, 
	10, 1, 43, 
	2, 8, 0, 20, 
	70, 54, 64, 
	4, 42, 28, 
	2, 37, 
	21, 
	13, 42, 28, 
	2, 34, 0, 47, 14, 47, 
	53, 117, 
	18, 38, 35, 
	2, 12, 0, 12, 0, 13, 0, 11, 
	72, 20, 53, 
	18, 39, 35, 
	2, 13, 0, 12, 0, 13, 0, 11, 
	72, 20, 59, 
	11, 1, 12, 
	2, 6, 0, 16, 
	54, 56, 70, 64, 
	15, 1, 35, 
	4, 15, 2, 13, 0, 14, 
	56, 54, 70, 64, 
	4, 42, 87, 
	3, 60, 
	18, 
	15, 42, 22, 
	4, 6, 2, 18, 0, 4, 
	10, 54, 76, 3, 
	9, 1, 34, 
	2, 20, 0, 15, 
	54, 76, 
	4, 38, 17, 
	4, 13, 
	20, 
	17, 24, 32, 
	2, 24, 1, 25, 0, 28, 0, 24, 
	72, 22, 
	10, 1, 18, 
	2, 28, 0, 8, 
	20, 54, 76, 
	13, 10, 32, 
	2, 27, 14, 25, 0, 25, 
	52, 20, 
	7, 48, 29, 
	3, 16, 
	32, 88, 120, 63, 
	13, 38, 8, 
	2, 17, 0, 17, 0, 27, 
	72, 20, 
	13, 39, 8, 
	2, 27, 0, 17, 0, 27, 
	72, 20, 
	5, 10, 30, 
	2, 57, 
	5, 36, 
	7, 32, 22, 
	4, 6, 
	61, 28, 31, 63, 
	5, 38, 17, 
	2, 24, 
	5, 111, 
	13, 10, 44, 
	3, 26, 13, 29, 0, 26, 
	52, 20, 
	12, 35, 25, 
	3, 2, 3, 4, 8, 15, 
	30, 
	9, 1, 18, 
	2, 28, 0, 8, 
	54, 76, 
	4, 1, 18, 
	2, 30, 
	27, 
	12, 42, 44, 
	3, 26, 14, 52, 13, 54, 
	134, 
	11, 45, 8, 
	0, 0, 4, 1, 
	73, 20, 6, 88, 
	211, 
	14, 32, 3, 9, 1, 0, 0, 3, 
	58, 32, 56, 114, 
	4, 42, 42, 
	3, 40, 
	119, 
	23, 10, 40, 
	9, 0, 3, 33, 0, 3, 0, 37, 2, 3, 
	52, 53, 20, 67, 
	8, 38, 28, 
	4, 5, 2, 34, 
	20, 
	13, 42, 28, 
	4, 5, 2, 34, 13, 47, 
	20, 140, 
	13, 10, 40, 
	8, 0, 3, 3, 0, 3, 
	52, 20, 
	13, 40, 37, 
	9, 1, 2, 37, 0, 1, 
	58, 20, 
	17, 40, 39, 
	8, 1, 2, 37, 0, 34, 0, 37, 
	72, 20, 
	17, 42, 44, 
	3, 26, 14, 54, 14, 52, 13, 29, 
	134, 135, 
	4, 35, 63, 
	3, 52, 
	113, 
	15, 64, 23, 
	14, 23, 4, 6, 0, 23, 
	20, 85, 53, 146, 
	10, 1, 24, 
	2, 13, 0, 14, 
	54, 56, 76, 
	4, 35, 19, 
	3, 38, 
	17, 
	19, 48, 42, 
	3, 40, 0, 41, 0, 22, 0, 38, 
	32, 73, 72, 59, 
	199, 
	0, 40, 
	59, 88, 88, 35, 
	15, 64, 65, 
	3, 53, 0, 53, 0, 29, 
	59, 53, 73, 85, 
	193, 
	118, 141, 
	0, 34, 49, 
	71, 
	5, 10, 11, 
	2, 5, 
	5, 36, 
	6, 1, 17, 
	2, 22, 
	5, 37, 147, 
	0, 44, 0, 
	66, 
	9, 10, 40, 
	9, 0, 3, 3, 
	111, 112, 
	4, 18, 47, 
	1, 32, 
	39, 
	14, 23, 53, 
	3, 32, 0, 32, 2, 27, 
	20, 32, 59, 
	5, 10, 45, 
	2, 44, 
	5, 111, 
	18, 27, 52, 
	4, 18, 2, 35, 0, 35, 0, 51, 
	41, 55, 74, 
	4, 35, 51, 
	3, 51, 
	108, 
	4, 42, 55, 
	3, 44, 
	47, 
	7, 42, 8, 
	2, 27, 
	24, 1, 73, 25, 
	196, 
	14, 32, 
	43, 
	196, 
	14, 25, 
	26, 
	23, 64, 64, 
	4, 1, 3, 9, 3, 14, 8, 6, 3, 44, 
	73, 32, 88, 29, 
	199, 
	0, 65, 
	53, 76, 34, 63, 
	9, 10, 75, 
	3, 42, 0, 42, 
	20, 52, 
	4, 1, 66, 
	2, 56, 
	20, 
	4, 42, 42, 
	3, 38, 
	17, 
	4, 42, 66, 
	3, 16, 
	121, 
	13, 10, 47, 
	14, 32, 2, 27, 0, 32, 
	52, 20, 
	9, 10, 47, 
	3, 32, 0, 32, 
	52, 20, 
	10, 1, 15, 
	2, 10, 0, 22, 
	54, 20, 76, 
	14, 25, 9, 
	3, 43, 0, 9, 0, 43, 
	42, 72, 76, 
	12, 29, 11, 
	2, 6, 0, 6, 2, 6, 
	59, 
	14, 42, 11, 
	2, 5, 4, 3, 14, 6, 
	20, 51, 50, 
	0, 39, 17, 
	111, 
	9, 48, 2, 
	2, 5, 0, 45, 
	20, 55, 
	7, 24, 61, 
	3, 44, 
	73, 20, 6, 88, 
	211, 
	3, 9, 4, 1, 8, 3, 0, 6, 
	88, 32, 116, 58, 
	15, 50, 20, 
	2, 48, 1, 49, 0, 48, 
	103, 20, 73, 55, 
	202, 
	0, 50, 0, 59, 
	53, 105, 74, 
	10, 27, 59, 
	2, 50, 0, 18, 
	106, 54, 76, 
	0, 47, 0, 
	63, 
	10, 1, 77, 
	2, 31, 0, 23, 
	20, 54, 76, 
	4, 42, 43, 
	3, 53, 
	109, 
	4, 56, 0, 
	3, 29, 
	33, 
	9, 10, 57, 
	3, 47, 0, 47, 
	52, 20, 
	18, 10, 57, 
	2, 34, 9, 5, 0, 47, 0, 5, 
	52, 20, 58, 
	4, 35, 89, 
	3, 64, 
	124, 
	1, 24, 0, 
	20, 6, 
	0, 54, 0, 
	126, 
	9, 35, 25, 
	3, 2, 12, 4, 
	5, 4, 
	8, 38, 44, 
	13, 29, 3, 26, 
	20, 
	4, 42, 67, 
	4, 11, 
	10, 
	4, 29, 30, 
	3, 57, 
	20, 
	4, 10, 44, 
	2, 26, 
	127, 
	9, 35, 25, 
	3, 2, 3, 4, 
	5, 11, 
	8, 1, 70, 
	4, 9, 2, 1, 
	49, 
	9, 56, 0, 
	4, 15, 13, 35, 
	104, 132, 
	9, 56, 0, 
	13, 35, 4, 14, 
	104, 133, 
	4, 1, 8, 
	2, 27, 
	128, 
	4, 10, 2, 
	2, 5, 
	130, 
	15, 1, 12, 
	2, 62, 0, 6, 0, 23, 
	54, 76, 38, 59, 
	4, 42, 32, 
	3, 25, 
	18, 
	9, 69, 9, 
	3, 43, 3, 0, 
	129, 131, 
	6, 69, 0, 
	3, 0, 
	20, 6, 149, 
	16, 42, 44, 
	13, 52, 14, 54, 13, 29, 3, 26, 
	135, 
	17, 10, 63, 
	3, 26, 13, 29, 0, 52, 14, 52, 
	52, 20, 
	9, 10, 63, 
	3, 52, 0, 52, 
	52, 20, 
	17, 10, 61, 
	3, 26, 14, 54, 0, 54, 13, 29, 
	52, 20, 
	9, 10, 61, 
	3, 54, 0, 54, 
	52, 20, 
	9, 1, 17, 
	2, 41, 0, 19, 
	54, 76, 
	4, 60, 13, 
	4, 0, 
	51, 
	5, 42, 9, 
	3, 43, 
	136, 10, 
	4, 42, 9, 
	3, 9, 
	137, 
	5, 22, 20, 
	3, 39, 
	19, 138, 
	14, 50, 0, 
	1, 49, 2, 58, 0, 11, 
	123, 54, 64, 
	4, 56, 81, 
	4, 9, 
	49, 
	4, 38, 15, 
	4, 0, 
	51, 
	9, 62, 0, 
	2, 28, 0, 8, 
	54, 76, 
	4, 56, 0, 
	2, 35, 
	45, 
	4, 15, 0, 
	4, 10, 
	139, 
	1, 63, 0, 
	20, 6, 
	2, 64, 0, 
	20, 85, 6, 
	22, 10, 75, 
	2, 46, 1, 47, 0, 46, 0, 45, 0, 42, 
	102, 72, 74, 
	9, 23, 74, 
	1, 32, 0, 32, 
	53, 20, 
	22, 10, 56, 
	3, 45, 0, 45, 9, 8, 0, 48, 0, 8, 
	52, 53, 58, 
	9, 10, 56, 
	3, 45, 0, 45, 
	52, 20, 
	0, 10, 29, 
	130, 
	4, 15, 0, 
	2, 48, 
	143, 
	13, 51, 42, 
	3, 38, 0, 40, 0, 38, 
	72, 20, 
	4, 15, 52, 
	2, 35, 
	126, 
	5, 72, 9, 
	3, 43, 
	129, 131, 
	1, 42, 0, 
	76, 10, 
	5, 69, 0, 
	6, 0, 
	5, 144, 
	0, 56, 0, 
	110, 
	9, 10, 32, 
	2, 25, 0, 25, 
	52, 20, 
	0, 73, 66, 
	115, 
	15, 32, 33, 
	3, 36, 6, 7, 0, 25, 
	54, 64, 14, 73, 
	5, 50, 0, 
	1, 49, 
	20, 6, 
	5, 35, 87, 
	3, 60, 
	20, 9, 
	5, 22, 0, 
	3, 39, 
	20, 6, 
	6, 1, 77, 
	2, 61, 
	5, 37, 147, 
	0, 15, 0, 
	6, 
	4, 38, 28, 
	2, 37, 
	21, 
	13, 32, 43, 
	3, 53, 0, 53, 0, 63, 
	20, 72, 
	9, 40, 83, 
	2, 37, 0, 1, 
	60, 20, 
	9, 40, 84, 
	2, 37, 0, 1, 
	60, 20, 
	9, 40, 85, 
	2, 37, 0, 1, 
	60, 20, 
	9, 40, 86, 
	2, 37, 0, 1, 
	60, 20, 
	4, 35, 32, 
	3, 25, 
	145, 
	4, 38, 15, 
	2, 19, 
	111, 
	4, 72, 32, 
	3, 25, 
	18, 
	1, 72, 0, 
	20, 6, 
	4, 40, 69, 
	2, 37, 
	148, 
	9, 40, 39, 
	2, 37, 0, 1, 
	60, 20, 
	9, 40, 37, 
	2, 37, 0, 1, 
	60, 20, 
	4, 75, 55, 
	3, 44, 
	23, 
	255,
};


const uint8_t verbs[] = {
65, 85, 84,
71, 79, 32,
197, 78, 84,
215, 65, 76,
195, 76, 73,
210, 85, 78,
46, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
71, 69, 84,
212, 65, 75,
208, 73, 67,
210, 69, 77,
208, 85, 76,
72, 69, 76,
210, 69, 83,
46, 32, 32,
68, 82, 79,
208, 85, 84,
204, 69, 65,
212, 72, 82,
68, 73, 71,
79, 78, 32,
87, 65, 86,
68, 85, 83,
195, 76, 69,
80, 82, 69,
208, 85, 83,
77, 79, 86,
211, 72, 79,
203, 73, 67,
66, 82, 69,
211, 77, 65,
83, 65, 86,
82, 69, 65,
46, 32, 32,
32, 32, 32,
79, 80, 69,
67, 76, 79,
84, 85, 82,
196, 73, 65,
76, 79, 79,
197, 88, 65,
73, 78, 86,
67, 73, 82,
46, 32, 32,
81, 85, 73,
68, 82, 73,
197, 65, 84,
83, 65, 87,
77, 73, 88,
72, 65, 77,
46, 32, 32,
83, 72, 82,
46, 32, 32,
76, 73, 83,
200, 69, 65,
83, 84, 65,
32, 32, 32,
83, 72, 65,
32, 32, 32,
83, 76, 73,
68, 65, 78,
89, 69, 76,
211, 67, 82,
211, 85, 77,
211, 65, 89,
195, 82, 89,
67, 85, 84,
211, 84, 65,
32, 32, 32,
82, 85, 66,
83, 77, 79,
46, 32, 32,
72, 85, 71,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
32, 32, 32,
	0,
};
const uint8_t nouns[] = {
65, 78, 89,
78, 79, 82,
83, 79, 85,
69, 65, 83,
87, 69, 83,
85, 80, 32,
68, 79, 87,
75, 78, 73,
67, 79, 70,
73, 68, 79,
73, 78, 86,
75, 69, 84,
72, 79, 76,
83, 87, 79,
80, 65, 84,
87, 73, 78,
67, 76, 79,
68, 79, 79,
67, 72, 85,
76, 65, 66,
71, 82, 65,
87, 65, 76,
66, 65, 76,
77, 69, 68,
67, 72, 73,
87, 82, 73,
208, 76, 65,
83, 72, 73,
83, 65, 70,
66, 82, 69,
65, 82, 77,
71, 76, 65,
82, 73, 78,
84, 85, 66,
70, 73, 82,
70, 76, 85,
195, 72, 73,
51, 56, 32,
83, 79, 79,
51, 51, 32,
72, 69, 65,
193, 78, 73,
67, 72, 69,
83, 84, 65,
66, 65, 71,
80, 73, 78,
83, 65, 87,
70, 79, 79,
210, 65, 66,
71, 65, 77,
83, 72, 79,
80, 65, 80,
83, 87, 69,
77, 65, 78,
195, 82, 73,
68, 79, 76,
66, 79, 65,
72, 65, 77,
71, 82, 65,
66, 85, 84,
80, 85, 80,
83, 84, 73,
83, 84, 65,
66, 79, 79,
67, 72, 65,
90, 65, 80,
80, 79, 84,
67, 69, 76,
66, 65, 82,
76, 79, 67,
76, 69, 68,
87, 79, 79,
86, 79, 73,
83, 73, 71,
70, 76, 79,
78, 65, 73,
77, 85, 77,
67, 82, 65,
83, 65, 80,
82, 79, 67,
65, 82, 79,
67, 82, 89,
210, 65, 86,
51, 52, 32,
51, 53, 32,
51, 54, 32,
51, 55, 32,
76, 69, 65,
77, 79, 65,
80, 65, 71,
	0,
};
const uint8_t automap[] = {
75, 78, 73,
	0,
87, 82, 73,
	2,
72, 69, 65,
	3,
71, 76, 65,
	4,
83, 72, 73,
	7,
73, 68, 79,
	9,
67, 76, 79,
	14,
80, 79, 84,
	16,
83, 79, 79,
	21,
82, 73, 78,
	25,
66, 65, 71,
	26,
70, 79, 79,
	32,
83, 87, 79,
	33,
84, 85, 66,
	36,
67, 72, 69,
	38,
83, 72, 79,
	39,
67, 72, 69,
	40,
78, 65, 73,
	42,
73, 68, 79,
	43,
68, 79, 76,
	44,
66, 79, 65,
	45,
72, 65, 77,
	47,
83, 65, 87,
	49,
80, 65, 80,
	51,
66, 79, 79,
	52,
83, 84, 65,
	53,
83, 84, 73,
	54,
71, 82, 65,
	59,
76, 69, 65,
	60,
82, 79, 67,
	63,
80, 65, 71,
	64,
	0,
};
#include <stdio.h>	/* Not really used but needed for perror */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <setjmp.h>
#include <termios.h>

#ifdef __linux__
#include <stdio.h>
#endif

static jmp_buf restart;

struct savearea {
  uint16_t magic;
  uint8_t carried;
  uint8_t lighttime;
  uint8_t location;
  uint8_t objloc[NUM_OBJ];
  uint8_t roomsave[6];
  uint8_t savedroom;
  uint32_t bitflags;
  int16_t counter;
  int16_t counter_array[16];
};

static char linebuf[81];
static char *nounbuf;
static char wordbuf[WORDSIZE + 1];

static uint8_t verb;
static uint8_t noun;
static const uint8_t *linestart;
static uint8_t linematch;
static uint8_t actmatch;
static uint8_t continuation;
static uint16_t *param;
static uint16_t param_buf[5];
static uint8_t rows, cols;
static uint8_t redraw;

static struct savearea game;

static void error(const char *p);

#define VERB_GO		1
#define VERB_GET	10
#define VERB_DROP	18

#define LIGHTOUT	16
#define DARKFLAG	15
#define LIGHT_SOURCE	9

/* Define this because 1 << n might be 16bit */
#define ONEBIT		((uint32_t)1)

#define REDRAW		1
#define REDRAW_MAYBE	2

#ifdef CONFIG_IO_CURSES

#include <curses.h>

#define REDRAW_MASK	(REDRAW|REDRAW_MAYBE)

static char wbuf[81];
static int wbp = 0;
static int xpos = 0, ypos = 0;
static int bottom;
static WINDOW *topwin, *botwin, *curwin;

static void flush_word(void)
{
  wbuf[wbp] = 0;
  waddstr(curwin, wbuf);
  xpos += wbp;
  wbp = 0;
}

static void new_line(void)
{
  xpos = 0;
  if (curwin == topwin)
    ypos++;
  else {
    scroll(curwin);
    ypos = bottom;
  }
  wmove(curwin, ypos, xpos);
}

static void char_out(char c)
{
  if (c == '\n') {
    flush_word();
    new_line();
    return;
  }
  if (c != ' ') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  if (xpos + wbp >= cols)
    new_line();
  flush_word();
  waddch(curwin, ' ');
  xpos++;
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}

static char readchar(void)
{
  wrefresh(botwin);
  return wgetch(botwin);
}

static void line_input(int m)
{
  int c;
  char *p = linebuf;

  do {
    wmove(botwin, ypos, xpos);
    wrefresh(botwin);
    c = wgetch(botwin);
    if (c == 8 || c == 127) {
      if (p > linebuf) {
        xpos--;
        mvwaddch(botwin, ypos, xpos, ' ');
        p--;
      }
      continue;
    }
    if (c > 31 && c < 127) {
      if (p < linebuf + 80 && xpos < cols - 1) {
        *p++ = c;
        mvwaddch(botwin, ypos, xpos, c);
        xpos++;
      }
      continue;
    }
  }
  while (c != 13 && c != 10);
  *p = 0;
  new_line();
}

static int saved_x;

static void begin_upper(void)
{
  saved_x = xpos;
  curwin = topwin;
  werase(topwin);
  ypos = 0;
  xpos = 0;
}

static void end_upper(void)
{
  flush_word();
  curwin = botwin;
  xpos = saved_x;
  ypos = bottom;
  wrefresh(topwin);
}

static void display_init(void)
{
  int trow;

  initscr();
  noecho();
  cbreak();
  nonl();

  getmaxyx(stdscr, rows, cols);

  if (rows < 16)
    error("display too small");

  trow = 10;
  if (rows / 2 < 10)
    trow = rows / 2;
  bottom = rows - trow;

  topwin = newwin(trow, cols, 0, 0);
  botwin = newwin(bottom--, cols, trow, 0);
  if (!topwin || !botwin)
    error("curses");
  scrollok(botwin, TRUE);
  curwin = botwin;
  new_line();
}

static void display_exit(void)
{
  endwin();
}

#elif defined(CONFIG_IO_CUSS)

/* ---- */

#include <termcap.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>

/* A mini look alike to David Given's libcuss. If useful will probably
   become a library. For now pasted around to experiment */

uint_fast8_t screenx, screeny, screen_height, screen_width;

static char *t_go, *t_clreol, *t_clreos;
static uint8_t conbuf[64];
static uint8_t *conp = conbuf;

extern void con_puts(const char *s);

/* Queue a character to the output buffer */
static int conq(int c)
{
	if (conp == conbuf + sizeof(conbuf)) {
		write(1, conbuf, sizeof(conbuf));
		conp = conbuf;
	}
	*conp++ = (uint8_t) c;
	return 0;
}

/* Make sure the output buffer is written */
void con_flush(void)
{
	write(1, conbuf, conp - conbuf);
	conp = conbuf;
}

static const char hex[] = "0123456789ABCDEF";

/* Put a character to the screen. We handle unprintables and tabs */
void con_putc(uint8_t c)
{
	if (c == '\t') {
		uint8_t n = 8 - (screenx & 7);
		while (n--)
			con_putc(' ');
		return;
	}
	if (c > 127) {
		con_puts("\\x");
		con_putc(hex[c >> 4]);
		con_putc(hex[c & 0x0F]);
		return;
	} else if (c == 127) {
		con_puts("^?");
		return;
	}
	if (c < 32) {
		con_putc('^');
		c += '@';
	}
	conq(c);
	screenx++;
adjust:
	if (screenx == screen_width) {
		screenx = 0;
		screeny++;
	}
}

/* Write a termcap string out */
static void con_twrite(char *p, int n)
{
#if !defined(__linux__)
	tputs(p, n, conq);
#else
	while (*p)
		conq(*p++);
#endif
}

/* Write a string of symbols including quoting */
void con_puts(const char *s)
{
	uint8_t c;
	while (c = (uint8_t) *s++)
		con_putc(c);
}

/* Add a newline */
void con_newline(void)
{
	if (screeny >= screen_height)
		return;
	conq('\n');
	screenx = 0;
	screeny++;
}

/* We need to optimize this but firstly we need to fix our
   tracking logic as we use con_goto internally but don't track
   that verus the true user values */
void con_force_goto(uint_fast8_t y, uint_fast8_t x)
{
	con_twrite(tgoto(t_go, x, y), 2);
	screenx = x;
	screeny = y;
}

void con_goto(uint_fast8_t y, uint_fast8_t x)
{
#if 0
	if (screenx == x && screeny == y)
		return;
	if (screeny == y && x == 0) {
		conq('\r');
		screenx = 0;
		return;
	}
	if (screeny == y - 1 && x == 0) {
		con_newline();
		return;
	}
#endif	
	con_force_goto(y, x);
}

/* Clear to end of line */
void con_clear_to_eol(void)
{
	if (screenx == screen_width - 1)
		return;
	if (t_clreol)
		con_twrite(t_clreol, 1);
	else {
		uint_fast8_t i;
		/* Write spaces. This tends to put the cursor where
		   we want it next time too. Might be worth optimizing ? */
		for (i = screenx; i < screen_width; i++)
			con_putc(' ');
	}
}

/* Clear to the bottom of the display */

void con_clear_to_bottom(void)
{
	/* Most terminals have a clear to end of screen */
	if (t_clreos)
		con_twrite(t_clreos, screen_height);
	/* If not then clear each line, which may in turn emit
	   a lot of spaces in desperation */
	else {
		uint_fast8_t i;
		for (i = 0; i < screen_height; i++) {
			con_goto(i, 0);
			con_clear_to_eol();
		}
	}
	con_force_goto(0, 0);
}

void con_clear(void)
{
	con_goto(0, 0);
	con_clear_to_bottom();
}

int con_scroll(int n)
{
	if (n == 0)
		return 0;
	/* For now we don't do backscrolls: FIXME */
	if (n < 0)
		return 1;
	/* Scrolling down we can do */
	con_force_goto(screen_height - 1, 0);
	while (n--)
		conq('\n');
	con_force_goto(screeny, screenx);
}

/* TODO: cursor key handling */
int con_getch(void)
{
	uint8_t c;
	con_flush();
	if (read(0, &c, 1) != 1)
		return -1;
	return c;
}

int con_size(uint8_t c)
{
	if (c == '\t')
		return 8 - (screenx & 7);
	/* We will leave unicode out 8) */
	if (c > 127)
		return 4;
	if (c < 32 || c == 127)
		return 2;
	return 1;
}

static int do_read(int fd, void *p, int len)
{
	int l;
	if ((l = read(fd, p, len)) != len) {
		if (l < 0)
			perror("read");
		else
			write(2, "short read from tchelp.\n", 25);
		return -1;
	}
	return 0;
}

static char *tnext(char *p)
{
	return p + strlen(p) + 1;
}

static int tty_init(void)
{
	int fd[2];
	pid_t pid;
	int ival[3];
	int n;
	int status;

	if (pipe(fd) < 0) {
		perror("pipe");
		return -1;
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		return -1;
	}

	if (pid == 0) {
		close(fd[0]);
		dup2(fd[1], 1);
		execl("/usr/lib/tchelp", "tchelp", "li#co#cm$ce$cd$cl$", NULL);
		perror("tchelp");
		_exit(1);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);

	do_read(fd[0], ival, sizeof(int));
	if (ival[0] == 0)
		return -1;
	do_read(fd[0], ival + 1, 2 * sizeof(int));

	ival[0] -= 2 * sizeof(int);
	t_go = sbrk((ival[0] + 3) & ~3);

	if (t_go == (void *) -1) {
		perror("sbrk");
		return -1;
	}

	if (do_read(fd[0], t_go, ival[0]))
		return -1;

	close(fd[0]);
	t_clreol = tnext(t_go);
	t_clreos = tnext(t_clreol);
	if (*t_clreos == 0)	/* No clr eos - try for clr/home */
		t_clreos++;	/* cl cap if present */
	if (*t_go == 0) {
		write(2, "Insufficient terminal features.\n", 32);
		return -1;
	}
	/* TODO - screen sizes */
	screen_height = ival[1];
	screen_width = ival[2];
	/* need to try WINSZ and VT ioctls */
	return 0;
}

static struct termios con_termios, old_termios;

void con_exit(void)
{
	tcsetattr(0, TCSANOW, &old_termios);
}

int con_init(void)
{
	int n;
	static struct winsize w;
	if (tty_init())
		return -1;
	if (tcgetattr(0, &con_termios) == -1)
		return -1;
	memcpy(&old_termios, &con_termios, sizeof(struct termios));
	atexit(con_exit);
	con_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
	con_termios.c_iflag &= ~(IXON);
	con_termios.c_cc[VMIN] = 1;
	con_termios.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &con_termios) == -1)
		return -1;
#ifdef VTSIZE
	n = ioctl(0, VTSIZE, 0);
	if (n != -1) {
		screen_width = n & 0xFF;
		screen_height = (n >> 8) & 0xFF;
	}
#endif
	if (ioctl(0, TIOCGWINSZ, &w) == 0) {
		if (w.ws_col)
			screen_width = w.ws_col;
		if (w.ws_row)
			screen_height = w.ws_row;
	}
	return 0;
}


/* ---- */

/* Glue to the library */

#define REDRAW_MASK	0

static char wbuf[81];
static int wbp = 0;
static int upper;

static void display_exit(void)
{
  con_newline();
  con_flush();
}

static void display_init(void)
{
  if (con_init())
    exit(1);
  con_clear();
  con_goto(screen_height - 1, 0);
}

static void flush_word(void)
{
  if (screenx)
    con_putc(' ');
  wbuf[wbp] = 0;
  con_puts(wbuf);
  wbp = 0;
}

static void move_on(void)
{
    /* Move on a line in the correct manner */
    if (upper) {
      con_clear_to_eol();
      con_newline();
    } else {
      con_scroll(1);
      con_goto(screen_height - 1, 0);
    }
}

static void char_out(char c)
{
  if (c != ' ' && c != '\n') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  /* Does the word not fit ? */
  if (screenx + wbp + 1 >= screen_width)
    move_on();
  /* Write out the word */
  flush_word();
  if (c == '\n')
    move_on();
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}

static void action_look(void);

static void line_input(int m)
{
  int c;
  char *p = linebuf;

  if (m == 0)
    action_look();

  do {
    c = con_getch();
    if (c == 8 || c == 127) {
      if (p > linebuf) {
        con_goto(screen_height - 1, screenx - 1);
        con_putc(' ');
        con_goto(screen_height - 1, screenx - 1);
        p--;
      }
      continue;
    }
    if (c > 31 && c < 127) {
      if (p < linebuf + 80 && screenx < screen_width - 1) {
        *p++ = c;
        con_putc(c);
      }
      continue;
    }
  }
  while (c != 13 && c != 10);
  *p = 0;
  con_scroll(1);
  con_goto(screen_height - 1, 0);
}

static char readchar(void)
{
  line_input(1);
  return *linebuf;
}


static uint8_t ly, lx;

static void begin_upper(void)
{
  ly = screeny;
  lx = screenx;
  flush_word();
  con_goto(0,0);
  upper = 1;
}

char xbuf[] = "<@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@><@>";

static void end_upper(void)
{
  flush_word();
  con_clear_to_eol();
  con_newline();
  upper = 0;
  xbuf[screen_width] = 0;
  con_puts(xbuf);  
  con_goto(ly, lx);
}

#else

#include <stdio.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <termios.h>

#define REDRAW_MASK	REDRAW

static char wbuf[80];
static int wbp = 0;
static int xpos = 0;

static void display_init(void)
{
  char *c;
#ifdef TIOCGWINSZ
  struct winsize w;
  if (ioctl(0, TIOCGWINSZ, &w) != -1) {
    rows = w.ws_row;
    cols = w.ws_col;
    return;
  }
#elif VTSIZE
  int16_t v = ioctl(0, VTSIZE, 0);
  if (v != -1) {
    rows =  v >> 8;
    cols = v;
    return;
  }
#endif
  c = getenv("COLS");
  rows = 25;
  cols = c ? atoi(c): 80;
  if (cols == 0)
    cols = 80;
}

static void display_exit(void)
{
}

static void flush_word(void)
{
  write(1, wbuf, wbp);
  xpos += wbp;
  wbp = 0;
}

static void char_out(char c)
{
  if (c == '\n') {
    flush_word();
    write(1, "\n", 1);
    xpos = 0;
    return;
  }
  if (c != ' ') {
    if (wbp < 80)
      wbuf[wbp++] = c;
    return;
  }
  if (xpos + wbp >= cols) {
    xpos = 0;
    write(1,"\n", 1);
  }
  flush_word();
  write(1," ", 1);
  xpos++;
}

static void strout_lower(const uint8_t *p)
{
  while(*p)
    char_out(*p++);
}

static void strout_lower_spc(const uint8_t *p)
{
  strout_lower(p);
  char_out(' ');
}

static void decout_lower(uint16_t v)
{
#ifdef __linux__
  char buf[9];
  snprintf(buf, 8, "%d", v);	/* FIXME: avoid expensive snprintf */
  strout_lower((uint8_t *)buf);
#else
  strout_lower((uint8_t *)_itoa(v));
#endif
}

static void strout_upper(const uint8_t *p)
{
  strout_lower(p);
}


static void line_input(int m)
{
  int l = read(0, linebuf, sizeof(linebuf));
  if (l < 0)
    error("read");
  linebuf[l] = 0;
  if (l && linebuf[l-1] == '\n')
    linebuf[l-1] = 0;
}

static char readchar(void)
{
  line_input(0);
  return *linebuf;
}

static void begin_upper(void)
{
  strout_upper("\n\n\n\n");
}

static void end_upper(void)
{
  uint8_t l = cols;
  char_out('\n');
  while(l--)
    char_out('-');
  char_out('\n');
}



#endif

/******************** Common code ******************/

static uint8_t yes_or_no(void)
{
  char c;
  do {
    c = readchar();
    if (c == 'Y'  || c == 'y' || c == 'J' || c == 'j')
      return 1;
  } while(c != -1 && c != 'N' && c != 'n');
  return 0;
}

static void exit_game(uint8_t code)
{
  display_exit();
  exit(code);
}

static void error(const char *p)
{
  display_exit();
  write(2, p, strlen(p));
  exit(1);
}

static uint8_t random_chance(uint8_t v)
{
  v = v + v + (v >> 1);	/* scale as 0-249 */
  if (((rand() >> 3) & 0xFF) <= v)
    return 1;
  return 0;
}

static char *skip_spaces(char *p)
{
  while(*p && isspace(*p))
    p++;
  return p;
}

static char *copyword(char *p)
{
  char *t = wordbuf;
  p = skip_spaces(p);
  memset(wordbuf, ' ', WORDSIZE+1);
  while (*p && !isspace(*p) && t < wordbuf + WORDSIZE)
    *t++ = *p++;
  while(*p && !isspace(*p))
    p++;
  return p;
}

static int wordeq(const uint8_t *a, const char *b, uint8_t l)
{
  while(l--)
    if ((*a++ & 0x7F) != toupper(*b++))
      return 0;
  return 1;
}

static uint8_t whichword(const uint8_t *p)
{
  uint8_t code = 0;
  uint8_t i = 0;

  if (*wordbuf == 0 || *wordbuf == ' ')
    return 0;		/* No word */
  i--;
  
  do {
    i++;
    if (!(*p & 0x80))
      code = i;
    if (wordeq(p, wordbuf, WORDSIZE))
      return code;
    p += WORDSIZE;
  } while(*p != 0);
  return 255;
}

static void scan_noun(char *x)
{
  x = skip_spaces(x);
  nounbuf = x;
  copyword(x);
  noun = whichword(nouns);
}

static void scan_input(void)
{
  char *x = copyword(linebuf);
  verb = whichword(verbs);
  scan_noun(x);
}

void abbrevs(void)
{
  char *x = skip_spaces(linebuf);
  const char *p = NULL;
  if (x[1] != 0 && x[1] != ' ')
    return;
  switch(toupper(*x)) {
    case 'N': 
      p = "NORTH";
      break;
    case 'E':
      p = "EAST";
      break;
    case 'S':
      p = "SOUTH";
      break;
    case 'W':
      p = "WEST";
      break;
    case 'U':
      p = "UP";
      break;
    case 'D':
      p = "DOWN";
      break;
    case 'I':
      p = "INVEN";
      break;
  }
  if (p)
    strcpy(linebuf, p);
}
  
static const uint8_t *run_conditions(const uint8_t *p, uint8_t n)
{
  uint8_t i;
  
  for (i = 0; i < n; i++) {
    uint8_t opc = *p++;
    uint16_t par = *p++ | ((opc & 0xE0) >> 5);
    uint8_t op = game.objloc[par];
    opc &= 0x1F;

    switch(opc) {
      case 0:
        *param++ = par;
        break;
      case 1:
        if (op != 255)
          return NULL;
        break;
      case 2:
        if (op != game.location)
          return NULL;
        break;
      case 3:
        if (op != 255 && op != game.location)
          return NULL;
        break;
      case 4:
        if (game.location != par)
          return NULL;
        break;
      case 5:
        if (op == game.location)
          return NULL;
        break;
      case 6:
        if (op == 255)
          return NULL;
        break;
      case 7:
        if (game.location == par)
          return NULL;
        break;
      case 8:
        if (!(game.bitflags & (ONEBIT << par)))
          return NULL;
        break;
      case 9:
        if (game.bitflags & (ONEBIT << par))
          return NULL;
        break;
      case 10:
        if (!game.carried)
          return NULL;
        break;
      case 11:
        if (game.carried)
          return NULL;
        break;
      case 12:
        if (op == 255 || op == game.location)
          return NULL;
        break;
      case 13:
        if (op == 0)
          return NULL;
        break;
      case 14:
        if (op != 0)
          return NULL;
        break;
      case 15:
        if (game.counter > par)
          return NULL;
        break;
      case 16:
        if (game.counter < par)
          return NULL;
        break;
      case 17:
        if (op != objinit[par]) 
          return NULL;
        break;
      case 18:
        if (op == objinit[par])
          return NULL;
        break;
      case 19:
        if (game.counter != par)
          return NULL;
        break;
      default:
        error("BADCOND");
    }
  }
  return p;
}

uint8_t islight(void)
{
  uint8_t l = game.objloc[LIGHT_SOURCE];
  if (!(game.bitflags & (ONEBIT << DARKFLAG)))
    return 1;
  if (l == 255 || l == game.location)
    return 1;
  return 0;
}

static void action_look(void)
{
  const uint8_t *e;
  const uint8_t *p;
  uint8_t c;
  uint8_t f = 1;
  const uint8_t **op = objtext;

  redraw = 0;

  begin_upper();

  if (!islight()) {
    strout_upper(itsdark);
    end_upper();
    return;
  }
  p = locdata[game.location].text;
  e = locdata[game.location].exit;
  if (*p == '*')
    p++;
  else
    strout_upper(youare);
  strout_upper(p);
  strout_upper(newline);
  strout_upper(obexit);

  for (c = 0; c < 6; c++) {
    if (*e++) {
      if (f)
        f = 0;
      else
        strout_upper(dashstr);
      strout_upper(exitmsgptr[c]);
    }
  }
  if (f)
    strout_upper(nonestr);
  strout_upper(dotnewline);
  f = 1;
  e = game.objloc;
  while(e < game.objloc + NUM_OBJ) {
    if (*e++ == game.location) {
      if (f) {
        strout_upper(canalsosee);
        f = 0;
      } else
        strout_upper(dashstr);
      strout_upper(*op);
    }
    op++;
  }
  end_upper();
}

static void action_delay(void)
{
  sleep(2);
}

static void action_dead(void)
{
  strout_lower(dead);
  game.bitflags &= ~(ONEBIT << DARKFLAG);
  game.location = lastloc;
  action_look();
}

static void action_quit(void)
{
  strout_lower(playagain);
  if (yes_or_no())
    longjmp(restart, 0);
  exit_game(0);
}

static void action_score(void)
{
  uint8_t *p = game.objloc;
  const uint8_t **m = objtext;
  uint8_t t = 0, s = 0;

  while(p < game.objloc + NUM_OBJ) {
    if (*m[0] == '*') {
      t++;
      if (*p == treasure)
        s++;
    }
    m++;
    p++;
  }

  strout_lower(stored_msg);
  decout_lower(s);
  strout_lower(stored_msg2);
  decout_lower((s * (uint16_t)100) / t);
  strout_lower(dotnewline);
  if (s == t)
    action_quit();
}

static void action_inventory(void)
{
  uint8_t *p = game.objloc;
  const uint8_t **m = objtext;
  uint8_t f = 1;

  strout_lower(carrying);
  if (game.carried == 0)
    strout_lower(nothing);
  else {  
    while(p < game.objloc + NUM_OBJ) {
      if (*p == 255) {
        if (!f)
          strout_lower(dashstr);
        else
          f = 0;
        strout_lower(*m);
      }
      m++;
      p++;
    }
  }
  strout_lower(dotnewline);
}

static char *filename(void)
{
  strout_lower("File name ? ");
  line_input(1);
  return skip_spaces(linebuf);
}

static void action_save(void)
{
  int fd;
  char *p = filename();
  if (*p == 0)
    return;
  game.magic = GAME_MAGIC;
  fd = open(p, O_WRONLY|O_CREAT|O_TRUNC, 0600);
  if (fd == -1 || write(fd, &game, sizeof(game)) != sizeof(game) || close(fd) == -1)
    strout_lower("Save failed.\n");
  close(fd);	/* Double closing is safe for non error path */
}

static int action_restore(void)
{
  while(1) {
    char *p = filename();
    int fd;

    if (*p == 0)
      return 0;

    fd = open(p, O_RDONLY, 0600);

    if (fd != -1 && read(fd, &game, sizeof(game)) == sizeof(game) && close(fd) != -1 &&
        game.magic == GAME_MAGIC)
      return 1;

    strout_lower("Load failed.\n");
    close(fd);
  }
}
  
static void moveitem(uint8_t i, uint8_t l)
{
  uint8_t *p = game.objloc + i;
  if (*p == game.location)
    redraw |= REDRAW_MAYBE;
  if (l == game.location)
    redraw |= REDRAW;
  *p = l;
}

static void run_actions(const uint8_t *p, uint8_t n)
{
  uint8_t i;

  for (i = 0; i < n; i++) {
    uint8_t a = *p++;
    uint8_t tmp;
    uint16_t tmp16;

    if (a < 50) {
      strout_lower_spc(msgptr[a]);
      continue;
    }
    if (a > 102 ) {
      strout_lower_spc(msgptr[a - 50]);
      continue;
    }
    switch(a) {
      case 51:	/* nop - check */
        break;
      case 52:	/* Get */
        if (game.carried >= maxcar)
          strout_lower(toomuch);
        else
          moveitem(*param++, 255);
        break;
      case 53: /* Drop */
        moveitem(*param++, game.location);
        break;
      case 54: /* Go */
        game.location = *param++;
        redraw |= REDRAW;
        break;
      case 55: /* Destroy */
      case 59: /* ?? */
        moveitem(*param++, 0);
        break;
      case 56:	/* Set dark flag */
        game.bitflags |= (ONEBIT << DARKFLAG);
        break;
      case 57:	/* Clear dark flag */
        game.bitflags &= ~(ONEBIT << DARKFLAG);
        break;
      case 58:	/* Set bit */
        game.bitflags |= (ONEBIT << *param++);
        break;
      /* 59 see 55 */
      case 60:	/* Clear bit */
        game.bitflags &= ~(ONEBIT << *param++);
        break;
      case 61:	/* Dead */
        action_dead();
        break;
      case 64:	/* Look */
      case 76:	/* Also Look ?? */
        action_look();
        break;
      case 62:	/* Place obj, loc */
        tmp = *param++;
        moveitem(tmp, *param++);
        break;
      case 63:	/* Game over */
        action_quit();
      case 65:	/* Score */
        action_score();
        break;
      case 66:	/* Inventory */
        action_inventory();
      case 67:	/* Set bit 0 */
        game.bitflags |= (ONEBIT << 0);
        break;
      case 68:	/* Clear bit 0 */
        game.bitflags &= ~(ONEBIT << 0);
        break;
      case 69:	/* Refill lamp */
        game.lighttime = lightfill;
        game.bitflags &= ~(ONEBIT << LIGHTOUT);
        moveitem(LIGHT_SOURCE, 255);
        break;
      case 70:	/* Wipe lower */
        /* TODO */
        break;
      case 71:	/* Save */
        action_save();
        break;
      case 72:	/* Swap two objects */
        tmp = game.objloc[*param];
        moveitem(*param, game.objloc[param[1]]);
        moveitem(param[1], tmp);
        param += 2;
        break;
      case 73:
        continuation = 1;
        break;
      case 74:	/* Get without weight rule */
        moveitem(*param++, 255);
        break;
      case 75:	/* Put one item by another */
        moveitem(*param, game.objloc[param[1]]);
        param += 2;
        break;
      case 77:	/* Decrement counter */
        if (game.counter >= 0)
          game.counter--;
        break;
      case 78:	/* Display counter */
        decout_lower(game.counter);
        break;
      case 79:	/* Set counter */
        game.counter = *param++;
        break;
      case 80:	/* Swap player and saved room */
        tmp = game.savedroom;
        game.savedroom = game.location;
        game.location = tmp;
        redraw |= REDRAW;
        break;
      case 81:	/* Swap counter and counter n */
        tmp16 = game.counter;
        game.counter = game.counter_array[*param];
        game.counter_array[*param++] = tmp16;
        break;
      case 82:	/* Add to counter */
        game.counter += *param++;
        break;
      case 83:	/* Subtract from counter */
        game.counter -= *param++;
        if (game.counter < 0)
          game.counter = -1;
        break;
      case 84:	/* Print noun, newline */
        strout_lower((uint8_t *)nounbuf);
        /* Fall through */
      case 86:	/* Print newline */
        strout_lower(newline);
        break;
      case 85:	/* Print noun */ 
        strout_lower((uint8_t *)nounbuf);
        break;
      case 87: /* Swap player and saveroom array entry */
        tmp16 = *param++;
        tmp = game.roomsave[tmp16];
        game.roomsave[tmp16] = game.location;
        if (tmp != game.location) {
          game.location = tmp;
          redraw |= REDRAW;
        }
        break;
      case 88:
        action_delay();
        break;
      case 89:
        param++;		/* SAGA etc specials */
        break;
      default:
        error("BADACT");
    }
  }
}

void next_line(void)
{
  uint8_t c = *linestart++;
  if (!(c & 0x80))
    linestart += 2;	/* Skip verb/noun */
  else if (!(c & 0x60))
    linestart++;	/* Skip random value */
  linestart += (c & 3) + 1;	/* Actions 1 - 4 */
  c >>= 1;
  c &= 0x0E;		/* 2 x conditions */
  linestart += c;
}

void run_line(const uint8_t *ptr, uint8_t c, uint8_t a)
{
  memset(param_buf, 0, sizeof(param_buf));
  param = param_buf;
  if (c)
    ptr = run_conditions(ptr, c);
  if (ptr) {
    actmatch = 1;
    param = param_buf;
    run_actions(ptr, a);
  }
  next_line();
}

void run_table(const uint8_t *tp)
{
  continuation = 0;
  linestart = tp;
  while(1) {
    uint8_t hdr;
    uint8_t c, a;
    tp = linestart;
    hdr = *tp++;
    c = (hdr >> 2) & 0x07;
    a = (hdr & 3) + 1;
    
/*    printf("H%02X c = %d a = %d\n", hdr, c, a); */
    if (hdr == 255)
      return;		/* End of table */
    if (hdr & 0x80) {
      if (hdr & 0x40) {	/* Auto 0 */
        if (continuation)
          run_line(tp, c, a);
        else
          next_line();
        continue;
      }
      continuation = 0;
      if (!(hdr & 0x20)) {	/* Auto number */
        if (random_chance(*tp++))
          run_line(tp, c, a);
        else
          next_line();
        continue;
      }
      run_line(tp, c, a);
    } else {
      if (actmatch)
        return;
/*      printf("VN %d %d\n", *tp, tp[1]); */
      linematch = 1;
      continuation = 0;
      if (*tp++ == verb && (*tp == noun || *tp == 0))
        run_line(tp+1, c, a);
      else
        next_line();
    }
  }
}

uint8_t autonoun(uint8_t loc)
{
  const uint8_t *p = automap;
  if (*wordbuf == ' ' || *wordbuf == 0)
    return 255;
  while(*p) {
    if (strncasecmp((const char *)p, wordbuf, WORDSIZE) == 0 && game.objloc[p[WORDSIZE]] == loc)
      return p[WORDSIZE];
    p += WORDSIZE + 1;
  }
  return 255;
}
  
void run_command(void)
{
  uint8_t tmp;
  run_table(actions);
  if (actmatch)
    return;
  if (verb == VERB_GET) {		/* Get */
    if (noun == 0)
      strout_lower(whatstr);
    else if (game.carried >= maxcar)
      strout_lower(toomuch);
    else {
      tmp = autonoun(game.location);
      if (tmp == 255)
        strout_lower(beyondpower);
      else
        moveitem(tmp, 255);
    }
    actmatch = 1;
    return;
  }
  if (verb == VERB_DROP) {		/* Drop */
    if (noun == 0)
      strout_lower(whatstr);
    else {
      tmp = autonoun(255);
      if (tmp == 255)
        strout_lower(beyondpower);
      else
        moveitem(tmp, game.location);
    }
    actmatch = 1;
    return;
  }
}

void process_light(void)
{
  uint8_t l;
  if ((l = game.objloc[LIGHT_SOURCE]) == 0)
    return;
  if (game.lighttime == 255)
    return;
  if (!--game.lighttime) {
    game.bitflags &= ~(ONEBIT << LIGHTOUT);	/* Check clear ! */
    if (l == 255 || l == game.location) {
      strout_lower(lightout);
      redraw |= REDRAW_MAYBE;
      return;
    }
  }
  if (game.lighttime > 25)
    return;
  strout_lower(lightoutin);
  decout_lower(game.lighttime);
  strout_lower(game.lighttime == 1 ? turn : turns);
}

void main_loop(void)
{
  uint8_t first = 1;
  char *p;

  action_look();
  
  while (1) {
    if (!first)
      process_light();
    else
      first = 0;
    verb = 0;
    noun = 0;

    run_table(status);

    if (redraw & REDRAW_MASK)
      action_look();
    strout_lower(whattodo);

    do {
      do {
        strout_lower(prompt);
        line_input(0);
        abbrevs();
        p = skip_spaces(linebuf);
      }
      while(*p == 0);

      scan_noun(p);
      if (noun && noun <= 6) {
        verb = VERB_GO;
        break;
      }
      scan_input();
      if (verb == 255)
        strout_lower(dontknow);
    } while (verb == 255);
    
    if (verb == VERB_GO) {
      if (!noun) {
        strout_lower(givedirn);
        continue;
      }
      if (noun <= 6) {
        uint8_t light = islight();
        uint8_t dir;

        if (!light)
          strout_lower(darkdanger);
        dir = locdata[game.location].exit[noun - 1];
        if (!dir) {
          if (!light) {
            strout_lower(brokeneck);
            action_delay();
            action_dead();
            continue;
          }
          strout_lower(cantgo);
          continue;
        }
        game.location = dir;
        redraw |= REDRAW;
        continue;
      }
    }
    linematch = 0;
    actmatch = 0;
    run_command();
    if (actmatch)
      continue;
    if (linematch) {
      strout_lower(notyet);
      continue;
    }
    strout_lower(dontunderstand);
  }
}

void start_game(void)
{
  memcpy(game.objloc, objinit, sizeof(game.objloc));
  game.bitflags = 0;
  game.counter = 0;
  memset(game.counter_array, 0, sizeof(game.counter_array));
  game.savedroom = 0;
  memset(game.roomsave, 0, sizeof(game.roomsave));
  game.location = startloc;
  game.lighttime = startlamp;
  game.carried = startcarried;
}

int main(int argc, char *argv[])
{
  display_init();
  setjmp(restart);
  strout_lower("Restore a saved game ? ");
  if (!yes_or_no() || !action_restore())
    start_game();
  main_loop();
}
