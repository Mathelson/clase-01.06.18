struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;

struct S_PeopleList
{
    int listSize;
    Person** people;
    int index;
};
typedef struct S_PeopleList PeopleList;//Varias listas de este tipo
                                       //Dejan de ser globales

PeopleList* list_initPeopleList(void);
Person* list_newPerson(void);//
void list_printPerson(Person* p);//
int list_enterPerson(Person* p);//
int list_getSize(PeopleList* pl);//
Person* list_get(PeopleList* pl,int i);//
void list_free(PeopleList* pl);//
void list_addPerson(PeopleList* pl, Person* p);//
 void list_remove(PeopleList* pl,int indexToDelete);//
