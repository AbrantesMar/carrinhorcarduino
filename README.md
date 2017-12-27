# carrinhorcarduino #arduino #robotica
Carrinho RC com Arduino

O Carrinho tem como componentes!

— Uma Placa Arduino UNO
— Um Módulo Bluetooth
— Um alto-falante
— Ponte H L298n Driver Motor Passo P/ Arduino Pic Automação
— Bateria 9v
— 2x Motores de passo  com rodas DC
— Base de carrinho para robo
— Rodinha de ... sei lá carrinho de feira

Como realizar as ligações:
 Lembrando que essas ligações foram feitas de acordo com minha necessidade, fiquem livre para mudar o que desejar.

Conectando a Ponte H:
    No meu driver fiz a conexão com o Arduino pela porta de energia que suporta alem de 5v.
Nessa porta conseguimos ter uma entrada de energia com a bateria de 9v, na placa vem descrevendo, com a entrada de 12v, um outro fio coloque na entrada central de corrente, ela será a entrada GND(Uma dica que na entrada de 12v, coloque um fio vermelho, e no GND preto, para lembrar de um positivo e o negativo).
    Nessa placa existe mais duas entradas laterais (OUT1, OUT2, OUT3, OUT4), coloque fios nas mesmas e conecte nos motores de passos.
    Bem ao lado das entradas da carga, existe conectores que sejam ligados da placa para o Arduino.
 Ligue fios nos pinos: IN1, IN2, IN3, IN4, eles serão responsáveis por receber as informações que o Arduino irá se comunicar. Com isso finalizamos as conexões do drive que controlara nosso passos com o carrinho.

Conectando a buzina:
    Se desejar, teria como adaptar uma buzina no seu carrinho com o Auto-falante/buzzer.
Como o buzzer é um conector muito pequeno, preferir colocar em uma mini-protoboard, não irei entrar muito em detalhes como funciona uma protoboard, porque vc não precisa de uma, apenas colocar um fio no pino negativo do buzzer, e um fio no positivo, como saber quem é quem? você terá dois pinos abaixo do buzzer, o maior é o positivo, o menor, e negativo. E ainda onde sai o som, tem também a indicação com o “+” no lado do positivo.

Conectando o Bluetooth:
    A conexão bluetooth é feita da seguinte forma, no modulo, conecte 4 cabos, nos pinos VCC, GND, TXD, RXD. Essas conexões são comunicadas com o Arduino nas portas: VCC = 5v, GND = GND a baixo da porta de 5v, TXD = 0, e RXD = 1. 

    Assim temos nosso Arduino com os seus componentes todos conectados. Podemos agora copiar o código na IDE, baixar o App no seu celular(celular tem que ter conexão bluetooth, e o link do app está nas referencias). 
 
 
Referências para o projeto:

http://www.instructables.com/id/Arduino-Bluetooth-RC-Car-Android-Controlled/
https://www.youtube.com/watch?v=ZAKyxNs2uuA&t=1101s

Link para controle remoto no celular:
https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=pt_BR
 
 
