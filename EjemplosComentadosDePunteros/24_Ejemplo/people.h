struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

int list_enterPerson(Person* p);
void list_printPerson(Person* p);


//int listSize;
void list_initPeopleList(void);
Person* list_newPerson(void);
void list_addPerson(Person* p);
int list_getSize(void);
Person* list_get(int i);
void list_free(void);
void list_remove(int indexToDelete);

