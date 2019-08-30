#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>


#define zerosFuncoes_aux_h
#define zerosFuncoes_aux_h

static const int max_it = 1E+3;
static const double e = 1E-3;

double f(double x);
double df(double x);

void newton();
void bisseccao();
void secante();


double f(double x){
    return x*x-2;
	//return x*log10(x) - 1.2;
}

double df(double x){
    return 2*x;
    //return log10(x) + 0.43429;
}

void newton(){
    double a, b, xn = 0, m_ant;
    int i = 0;

    printf("Entre com o intervalo [a, b]:\n");
    scanf("%lf %lf", &a, &b);
    system("cls");
    
    if(df(a) > df(b)){
        xn = a;
    }
    else{
        xn = b;
    }
    
    m_ant = xn;
    while (i < max_it){
        if(f(a) == 0){
            printf("A raiz � %lf.\n", a);
            return;
        }

        if(f(b) == 0){
            printf("A raiz � %lf.\n", b);
            return;
        }

        if(f(a)*f(b) < 0){
            double m = 0;
            double fxn = 0;
            double dfxn = 0;
            fxn = f(xn);
            dfxn = df(xn);
            m = xn-(fxn/dfxn);
            
			printf("\nResultado itera��o %d: \t%.4f\nValor x[%d]:\t%.2f", i, m,i, xn);
            
			if(f(m) == 0 || fabs(f(m)-f(m_ant)) < e){
                printf("\nA raiz � %lf.\n", m);
                return;
            }
            m_ant = m;
            xn = m;
        }
        else{
            printf("Intervalo n�o cont�m ra�z.\n");
            printf("Entre outro intervalo.\n");
            scanf("%lf %lf", &a, &b);
            m_ant = b;
            i = 0;
        }
        i++;
    }
    printf("N�mero m�ximo de itera��es atingido.\n");
}

void bisseccao(){
    double a, b, m_ant;
    int i = 0;

    printf("Entre com o intervalo [a, b]:\n");
    scanf("%lf %lf", &a, &b);
    m_ant = b;
    while (i < max_it){
        if(f(a) == 0){
            printf("A raiz � %lf.\n", a);
            return;
        }

        if(f(b) == 0){
            printf("A raiz � %lf.\n", b);
            return;
        }

        if(f(a)*f(b) < 0){
            double m = (a + b) / 2.0;
            printf("\nResultado itera��o %d: \t%.4f\nValor a:\t%.2f\nValor b:\t%.2f", i, m, a, b);
            
			if(f(m) == 0 || fabs(f(m)-f(m_ant)) < e){
                printf("\nA raiz � %lf.\n", m);
                return;
            }

            if(f(a)*f(m) < 0)
                b = m;
            else
                a = m;

            m_ant = m;
        }
        
		else{
            printf("Intervalo n�o cont�m ra�z.\n");
            printf("Entre outro intervalo.\n");
            scanf("%lf %lf", &a, &b);
            m_ant = b;
            i = 0;
        }
        i++;
    }
    printf("N�mero m�ximo de itera��es atingido.\n");
}

int main(int argc, const char * argv[]){
    setlocale(LC_ALL, "PORTUGUESE");
    int op;

    do{
        printf("\n");
        printf("Op��o 1: Bissec��o.\n");
        printf("Op��o 2: Newton.\n");
        printf("Op��o 0: Sair.\n\n");
        printf("Digite uma op��o.\n");
        scanf("%d", &op);

        switch (op){
        case 1:
            bisseccao();
            break;

        case 2:
            newton();
            break;
 	   }
	}
	
    while(op != 0);
    printf("Obrigado!\n");
    return 0;
}
