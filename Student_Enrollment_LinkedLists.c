#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAXx 30

typedef struct node
{
    char ime[MAXx];
    char prezime[MAXx];
    int index;
    char studijskiProg[MAXx];
    int godina;
    struct node* next;
} Node;

typedef struct listHeader {
    Node* head, * tail;
    int numElem,numElemMax;
} ListHeader;

ListHeader* nnode;

char* readLine(int prov)
{
    char* old_word = NULL, * new_word, c;
    int i = 0;
    if (prov == 0) {
        c = getchar();
    }
    while ((c = getchar()) != '\n')
    {
        new_word = realloc(old_word, (i + 1) * sizeof(char));
        if (!new_word)
        {
            printf("Mem greska");
            break;
        }
        else
        {
            old_word = new_word;
        }
        old_word[i] = c;
        i++;
    }
    if (c == '\n' && old_word==NULL)
    {
        return NULL;
    }
    new_word = realloc(old_word, (i + 1) * sizeof(char));
    if (!new_word)
    {
        printf("Mem greska");
        i--;
    }
    else
        old_word = new_word;
    old_word[i] = '\0';
    c = '\0';
    return old_word;
}

char** ReadLines(Node* head,int n)
{
    char c, ** niz = NULL;
    char* line;
    int brrrr = 0,i=0,j=0;
    Node* last = NULL;
    Node* node = NULL;
    nnode=malloc(sizeof(ListHeader));
    int prov = 0;
    while (j<n)
    {
        line = readLine(prov);
        prov++;
        if (!strlen(line))
        {
            free(line);
            break;
        }
        niz = realloc(niz, (brrrr + 1) * sizeof(niz));
        niz[(brrrr)++] = line;
        j++;
    }
    while (i < brrrr) {
        node = malloc(sizeof(Node));
        if (!node)
        {
            printf("Mem greska");
            break;
        }
        int br = 0;
        char pom[MAXx];
        c = niz[i][br];
        while (c != ' ') {
            node->ime[br] = niz[i][br];
            br++;
            c = niz[i][br];
        }
        node->ime[br] = '\0';
        //strcpy(node->ime, pom);
        int brpom = 0;
        br++;
        c = niz[i][br];
        while (c != ' ') {
            //pom[brpom] = niz[i][br];
            node->prezime[brpom] = niz[i][br];
            br++;
            brpom++;
            c = niz[i][br];
        }
        node->prezime[brpom] = '\0';
        //strcpy(node->prezime, pom);
        brpom = 0;
        br++;
        c = niz[i][br];
        while (c != '/') {
            pom[brpom] = c;
            brpom++;
            br++;
            c = niz[i][br];
        }
        pom[brpom] = '\0';
        node->index = atoi(pom);
        brpom = 0;
        br++;
        c = niz[i][br];
        while (c != ' ') {
            pom[brpom] = c;
            brpom++;
            br++;
            c = niz[i][br];
        }
        pom[brpom] = '\0';
        node->godina = atoi(pom);
        brpom = 0;
        br++;
        char pr[MAXx];
        c = niz[i][br];
        while (c != '\0') {
            node->studijskiProg[brpom] = c;
            brpom++;
            br++;
            c = niz[i][br];
        }
        node->studijskiProg[brpom] = '\0';
        node->next = NULL;
        if (last == NULL)
        {
            head = node;
            nnode->head = head;
        }
        else
            last->next = node;
        last = node;
        nnode->tail = last;
        i++;
        
    }
    nnode->numElem = brrrr;
    return head;
}


int CheckNode(Node* head) {
    //ListHeader* pom = NULL;
    int i = 0;
    Node* current = head;
    while (current) {
        i++;
        current = current->next;
    }
    current = head;
    if (head == NULL) {
        printf("Red je prazan!!!\n");
        return 0;
    }
    else if (nnode->head == head && nnode->numElem == nnode->numElemMax) {
        printf("Red je pun!!!\n");
        return 1;
    }
    else {
        printf("Red nije ni prazan a ni pun!!!\n");
        return 2;
    }
}

Node* DohvatiElem(Node* head) {
    Node* current = head;
    int i = 0,odg;
    while (current) {
        i++;
        current = current->next;
    }
    current = head;
    printf("Sa kojeg mesta zelite dohvatiti element od 0 do %d?\n",i-1);
    scanf("%d", &odg);
    i = 0;
    while (i < odg) {
        current = current->next;
        i++;
    }
    //Stampanje dodatnih 0,da bude 4 cifre za index
    if (current->index < 10) {
        printf("Dohvaceni element tj studenta na upisu je: %s %s 000%d/%d %s\n", current->ime, current->prezime, current->index, current->godina, current->studijskiProg);
    }
    else if (current->index < 100) {
        printf("Dohvaceni element tj studenta na upisu je: %s %s 00%d/%d %s\n", current->ime, current->prezime, current->index, current->godina, current->studijskiProg);
    }
    else if (current->index < 1000) {
        printf("Dohvaceni element tj studenta na upisu je: %s %s 000%d/%d %s\n", current->ime, current->prezime, current->index, current->godina, current->studijskiProg);
    }
    else {
        printf("Dohvaceni element tj studenta na upisu je: %s %s %d/%d %s\n", current->ime, current->prezime, current->index, current->godina, current->studijskiProg);
    }
    return current;
}

Node* DodavanjeElem(Node* head) {
    Node* current = head,*node=NULL;
    int i = 0;
    char* student;
    char c;
    int prov = 0;
    while (current->next) {
        current = current->next;
    }
    student = readLine(prov);
    if (!strlen(student))
    {
        free(student);
        return NULL;
    }
    node = malloc(sizeof(Node));
    if (!node)
    {
        printf("Mem greska");
        return NULL;
    }
    int br = 0;
    char pom[MAXx];
    c = student[br];
    while (c != ' ') {
        node->ime[br] = student[br];
        br++;
        c = student[br];
    }
    node->ime[br] = '\0';
    int brpom = 0;
    br++;
    c = student[br];
    while (c != ' ') {
        node->prezime[brpom] = student[br];
        br++;
        brpom++;
        c = student[br];
    }
    node->prezime[brpom] = '\0';
    brpom = 0;
    br++;
    c = student[br];
    while (c != '/') {
        pom[brpom] = c;
        brpom++;
        br++;
        c = student[br];
    }
    pom[brpom] = '\0';
    node->index = atoi(pom);
    brpom = 0;
    br++;
    c = student[br];
    while (c != ' ') {
        pom[brpom] = c;
        brpom++;
        br++;
        c = student[br];
    }
    pom[brpom] = '\0';
    node->godina = atoi(pom);
    brpom = 0;
    br++;
    c = student[br];
    char pr[MAXx];
    while (c != '\0') {
        node->studijskiProg[brpom] = c;
        brpom++;
        br++;
        c = student[br];
    }
    node->studijskiProg[brpom] = '\0';


    current->next = node;
    nnode->tail = node;
    node->next = NULL;
    printf("Dodat je novi clan u listu cekanja!!!!\n");
    nnode->numElem = nnode->numElem++;
    return head;
}

Node* Upis(Node* head) {
    Node* current = head;
    Node* pom = head;
    Node* temp = NULL;
    Node* node = NULL;
    double x,r;
    printf("Unesi vrednost praga X tako da vazi da je 0<=X<=0.5: \n");
    scanf("%lf", &x);
    while (current) {
        r = ((double)rand() / (RAND_MAX));
        if (r > x) {
            printf("Upisani student je: %s %s %d/%d %s\n", current->ime, current->prezime, current->index, current->godina, current->studijskiProg);
            if (current == head) {
                temp = head;
                head = head->next;
                current = head;
                free(temp);
                nnode->numElem = nnode->numElem - 1;
                nnode->head = head;
            }
        }
        else {
            //ako nije veci od x pa se prebacuje lik na poslednje mesto
            while (pom->next) {
                pom = pom->next;
            }
            //pom je islo do poslednjeg tako da mu je next na NULL gde se ubacuje ovaj sto nije upisan
            //head i current se pomeraju na sledeceg
            temp = head;
            head = head->next;
            current = head;
            //pravi se node koji ide na poslednje mesto
            node = malloc(sizeof(Node));
            if (!node)
            {
                printf("Mem greska");
                return NULL;
            }
            //node se povezuje na pom next koji je bio null i postaje poslednji u redu
            pom->next = node;
            nnode->tail = node;
            // kopira se data u taj poslednji node da bude identican kao taj sto nije upisan
            strcpy(node->ime,temp->ime);
            strcpy(node->prezime, temp->prezime);
            node->index = temp->index;
            node->godina = temp->godina;
            strcpy(node->studijskiProg, temp->studijskiProg);
            node->next = NULL;
            //prvog izbacujemo jer smo ga iskopirali u poslednjeg
            free(temp);
        }

    }

    return head;
}

int main()
{
    Node* niz = NULL, *pomniz = NULL;
    int izbor, o = 0, n, red,broj;
    printf("Koliko biste max studenata da ceka u redu: \n");
    scanf("%d", &broj);
    
    while (o < 2)
    {
        printf("---------------MAIN MENU---------------\n------1.Unos studenata\n------2.Provera reda(pun, prazan)\n------3.Dohvatanje elementa niza\n------4.Dodavanje elementa u niz\n------5.Upisivanje studenata iz reda\n------6.Quit\n---------------------------------------\n");
        scanf("%d", &izbor);
        switch (izbor)
        {
            case 1:
                printf("Koliko studenata je u redu (mora da bude <= od maxa):\n");
                scanf("%d", &n);
                while (n > broj) {
                    printf("Nije dobro uneto pokusaj ponovo!\n");
                    scanf("%d", &n);
                }
                if (n <= broj) {
                    printf("Unesite studente u obliku:\nime prezime index/godina studijskiProgram(npr. SI ili ER)\n");
                    niz = ReadLines(niz, n);
                    nnode->numElemMax = broj;
                }
                //else printf("Nije dobro uneto pokusaj ponovo!\n");
                
                break;
            case 2:
                red=CheckNode(niz);
                break;
            case 3:
                pomniz=DohvatiElem(niz);
                //printf("Dohvaceni element tj studenta na upisu je: %s %s %d/%d %s", &pomniz->prezime, &pomniz->ime, &pomniz->index, &pomniz->godina, &pomniz->studijskiProg);
                break;
            case 4:
                red = CheckNode(niz);
                if (red != 1 && red != 0) {
                    printf("Unesite studenta u obliku:\nime prezime index/godina studijskiProgram(npr. SI ili ER)\n");
                    niz = DodavanjeElem(niz);
                }
                else if (red == 1) printf("Ne mozete dodati nove studente,jer je red pun!!!\n");
                else { printf("Ne mozete dodati nove studente,jer je red prazan. Unesite studente prvo!!!\n"); }
                break;
            case 5:
                niz=Upis(niz);
                break;
            case 6:return -1; break;
            default:printf("Nije dobro uneseno pokusaj ponovo!!!\n"); break;
        }
    }
    return 0;
}