#include <iostream>

using namespace std;

int main(){
    
    void verificarTensao(void);
    
    int escolha = 0;
    
    cout << " Bem vindo ao menu iterativo" << "\n";
    
    while(escolha != 5){
        
        cout << "--------------------MENU--------------" << endl;
        cout << "1. Analisar nível de tensão da bateria" << endl;
        cout << "2. Varredura de sensores de corrente dos inversores" << endl;
        cout << "3. Simulação de teste de descarga com corrente de seguraça" << endl;
        cout << "4. Encerrar sistema" << endl;
        
        cout << "Opção digitada: "; cin >> escolha;
        
        if( (escolha >= 1 ) and ( escolha <= 4)){
            
            switch(escolha){
                case 1:
                    cout << "\nResultado da medição da tensão" << endl;
                    
                    verificarTensao();
                    
                    break;
                case 2:
                    cout << "\nVarredura feita" << endl;
                    break;
                case 3:
                    cout << "\nSimulação de teste de descarga feita" << endl;
                    break;
                case 4:
                    cout << "\nEncerrando sistema" << endl;
                    escolha = escolha + 1;
                    break;
            }
            
        } else{
            cout << "Você digitou um valor não válido" << endl;
        }
        
    }
    escolha = 0;
    
    return 0;
}

 void verificarTensao(){
        float valor;
        
        cout << "Digite o valor da tensão medido no banco de baterias" << endl;
        cout << "Valor medido: ";
        cin >> valor;
        
        cout << "\nResultado: ";
        
        if(valor < 42){
            cout << "Subtensão severa! Bateria descarregada." << endl;
        }
        else if((valor >= 42) and (valor <= 47.9)){
            cout << "Nível de carga baixo. Recomenda-se recarga solar." << endl;
        }
        else if((valor >= 48)and(valor <= 56)){
            cout << "Operação em regime nominal/flutuação." << endl;
        }
        else{
            cout << "                ALERTA!\n";
            cout << "Sobretensão! Risco de sobrecarga térmica!" << endl;
        }
    }