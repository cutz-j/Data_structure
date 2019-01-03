#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"


NameCard * MakeNameCard(char * dummy, char * name, char * phone) {
	NameCard * newCard = (NameCard *)malloc(sizeof(NameCard));
	strcpy_s(newCard->dummy, strlen(dummy)+1, dummy);
	strcpy_s(newCard->name, strlen(name)+1, name);
	strcpy_s(newCard->phone, strlen(phone) + 1, phone);
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("%s \n", pcard->name);
	printf("%s \n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name) {
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy_s(pcard->phone, strlen(phone)+1, phone);
}