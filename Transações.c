#include <stdio.h>

int main(){
char transacoes[5][5];
int codigo[5],i,j;
float valor[5],totalavista=0,totalaprazo=0,valortotal=0;

for(i=0;i<5;i++){
    printf("transacao %d\n",i+1);
    printf("Codigo:");
    scanf("%d",&codigo[i]);
    printf("a compa foi V - vista ou P - a prazo:");
    scanf(" %s",&transacoes[i]);
    printf("valor da transacao:");
    scanf("%f",&valor[i]);
    if(transacoes[i][0] == 'v' || transacoes[i][0] == 'V'){
        totalavista += valor[i];
    }
    if(transacoes[i][0] == 'p' || transacoes[i][0] == 'P'){
        totalaprazo += valor[i];
    }
    valortotal += valor[i];
}
printf("Valor total das compras a vista:%.2f\n",totalavista);
printf("Valor total das compras a prazo:%.2f\n",totalaprazo);
printf("Valor total das transsacoes:%.2f\n",valortotal);
printf("Valor total da primeira parcela :%.2f",(totalaprazo*0.10)/3);

}
