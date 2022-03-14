#define _CRT_SECURE_NO_WARNINGS
#include "StructFile.h"
//XPOTTOOOOO

//Declarar funções


int MainFunction()
{
        int optionselected;
        setlocale(LC_ALL, "Portuguese");// caracteres portugues aceites

        printf("\nM E N U\n");
        printf("\nPor favor selecione qual operação pretendida\n");
        printf("1 - Insercao de um novo processo \n");
        printf("2 - Pesquisar um processo pelo codigo\n");
        printf("3 - Listagem dos processos por ordem crescente\n");
        printf("4 - Alterar um processo\n");
        printf("5 - Remover um processo\n");
        printf("6 - Simular um processo\n");
        printf("7 - Armazenar os processos\n");
        printf("8 - Carregar os processos\n");
        printf("O - SAIR\n");

        do
        {
            scanf(" %d", &optionselected);
            system("cls");
            //clrscr();
        } while ((optionselected < 0) || (optionselected > 8));

        return(optionselected);

}


struct Job* CreateJob()
{
    struct Job* newjob = NULL;
    newjob = (struct Job*)malloc(sizeof(struct Job));
    if (newjob != NULL){
        int* operation, * machine, * cycletime, getmachines, getcycletime,op;
        const size_t MachinesPerOp;

        printf("Quantas operações terá?\n");
        scanf("%d", &op);
        newjob->operation = &op;

        for (int i = 0; i < op; i++) {

            machine = malloc(*newjob->operation * sizeof(int));
            cycletime = malloc(*newjob->operation * sizeof(int));
            printf("Quantas máquinas terá a operação %d ?\n", i + 1);
            scanf("%d", &MachinesPerOp);
            //int* arrayexample=(int*)malloc(sizeof(int)* MachinesPerOp);
            newjob->machine = (int*)malloc(sizeof(int)* MachinesPerOp);//ocupar memoria para o nr de elementos que o utilizador pretende
            newjob->cycletime = (int*)malloc(sizeof(int) * MachinesPerOp);//ocupar memoria para o nr de elementos que o utilizador pretende
            for (int x = 0; x < MachinesPerOp; x++) {


                printf("Qual a máquina associada %d ?\n", x + 1);
            
                scanf("%d", &getmachines);
                newjob->machine[x] = getmachines;
                //arrayexample[x] = getmachines;
            
                printf("Qual o tempo de ciclo %d ?\n", x + 1);
                scanf("%d", &getcycletime);
                newjob->cycletime[x] = getcycletime;

            }
            /*
            for (int x = 0; x < MachinesPerOp; x++) {
                printf("valor no indice: %d é ======   %d\n",x, newjob->machine[x]);
            }*/
        
        }
            if (init == 0)
            {
                init= final = newjob;
                init->next = init;
                init->prev = init;
                // Atribuir os endereços e guardar no init e no final(porque é a 1 vez)
            }
            else {

                final->next = newjob; // atribuir o novo valor
                newjob->prev = final; // ficar com o valor velho
                init->prev = newjob;// atribuir o proximo valor
                final = newjob; //
            }
    printf("Processo foi criado com sucesso!\n");
    return newjob;
    }
    else {
        printf("Alocação de um novo processo falhou!!\n");
        return NULL;

    }
    // breakpoint para entender melhor esta função do azevedo
}

int main() {

        init = 0;

        int optionselected;//operation, machine, cycletime;
        int flag; // garantir que nao se faz a mesma operação 2x
        do
        {
            optionselected = MainFunction();
    
            switch (optionselected)
            {
    
            case 1:
      
                while (optionselected == 1)
                {      
                   // flag = Same(optionselected);
    
                    //if (flag == 0)
                    //{
                        //struct Job *insertjob = GetValuesToInsertNewJob();
                    if (CreateJob() == NULL) {
                        printf("Não criou novo processo , repetir ? Presse 1 para tal! \n");

                    }
                        
                    //}
                    //else {
    
                    //    printf("Código do Cenario ja existe!!\n");
                    //}
    
    
                    printf("Continuar a Inserir ?\n");
                    printf("1-Sim 0-Nao\n");
                    scanf( "%d", &optionselected);
    
                }

            }
        } while (optionselected == 0);
        printf("Consola irá encerrar\n");
        //sleep(1);
        exit(0);

}