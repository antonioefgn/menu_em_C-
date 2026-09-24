#include <iostream>
#include <vector>

using namespace std;

int main(){


    void varreduraInversor(void);
    void verificarTensao(void);
    void testeDescarga(void);
    
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
                    cout << "\nResultado da varredura" << endl;
                    varreduraInversor();

                    break;
                case 3:
                    cout << "\nResultado da simulação do teste de descarga" << endl;
                    testeDescarga();

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
        
        do{
            cout << "Digite o valor da tensão medido no banco de baterias" << endl;
            cout << "Valor medido: ";
            cin >> valor;
            
            if ((valor < 0) and (valor > 80)){
                cout << "Valor inválido!" << endl;
            }
        }while((valor < 0) and (valor > 80));
        
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

void varreduraInversor(){
    int inversores;
    float temporario, media = 0;
    vector<float> corrente;

    cout << "Digite a quantidade de inversores" << endl;
    cout << "Quantidade: ";
    cin >> inversores;

    for(int i = 0; i < inversores; i++){
        cout << "Digite o valor da corrente do inversor " << i + 1 << ": " << endl;
        cin >> temporario;

        if(temporario >= 0){
            corrente.push_back(temporario);
            media += temporario;

        }else{
            cout << "O sensor está com defeito de comunicação." << endl;
            cout << "O valor informado será descartado da medição!" << endl;
        }
    }

    media = media/corrente.size();

    cout << "Sensores válidos: " << corrente.size() << endl;
    cout << "A corrente média da usina é de " << media << " A " << endl;
}

void testeDescarga(){
    float bancoBaterias = 48, drecremento = 1.5;

    for(float i = 1; i <= 5 ; ++i){
        
        bancoBaterias = bancoBaterias - drecremento;

        cout << " Ciclo " << i << " tensão: " << bancoBaterias << " V " << endl;

        if( bancoBaterias == 40.5 ){
            cout << "CORTE DE EMERGÊNCIA ACIONADO!" << endl;
        }
    }
}