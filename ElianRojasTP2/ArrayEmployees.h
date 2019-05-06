typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}Employee;

typedef struct
{
    int idSector;
    char sectorName [20];
}str_sector;


int findEmptyEmployee(Employee findFree[],int totalElements,int isFreeIndicator);

int initEmployees(Employee * list ,int len);

void initIds (Employee * employeeN,int len);

int isAllEmpty(Employee*list , int len);

void chargeEmployeeData(char name[] , char lastName[] , float * salary,int * sector);

int printEmployees(Employee * list, int length , str_sector * sector);

int printOneEmployee(Employee * oneEmployee , int id , int length , str_sector * sector);

int addEmployee(Employee list[],int len, char name[],char lastName[] , float salary , int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id , str_sector * sector);

int sortEmployeesBySector(Employee * list, int len);

int sortEmployeesByName(Employee * list, int len);

void printSalary(Employee list[] , int len);

void hardCode(Employee list[]);

void modifyEmployee (Employee list[],int len,int id);
