#include <iostream>

using namespace std;

int main(){
    
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
                    cout << "\nNível de tensão medido" << endl;
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