# Lixeira inteligente

# Informações gerais
* Universidade Presbiteriana Mackenzie 
* Nome: Davi Oliveira Netzer / Micaelli Sousa Guimarães
* TIA: 10415374/10415827
* Disciplina: Objetos Inteligentes Conectados 
* Profº: ANDRE LUIS DE OLIVEIRA 

# Descrição do Projeto
Este projeto/artigo científico é a estruturação de uma pesquisa relacionada a Internet das Coisas (IoT) e sua aplicação na área residencial e/ou comercial. Após análise, vive-se numa mudança de hábitos e paradigmas por conta da pandemia causada pelo Corona vírus (sars-cov-2), obrigando a sociedade como todo a reeducação de alguns hábitos, banais, como abrir um cesto de lixo. O estudo propõe aplicação pratica de automação de abertura de cestos de lixo, assim, evitando o contato e possível contaminação – residencial e até em hospitais, utlizando tambem o protocolo MQTT para acionamento remoto.

# Montagem dos componentes do projeto

![projeto_bb](https://user-images.githubusercontent.com/20358075/144297542-4df04eb3-8611-4e30-a4d4-072ade3d5823.jpg)

![20211201_091814](https://user-images.githubusercontent.com/20358075/144297219-fc7a58e6-421c-4d06-acd7-2e90a7764980.jpg)

# Resultado final
![20211201_154604](https://user-images.githubusercontent.com/20358075/144297308-f61f9072-cd69-4af4-90e5-1301d3276e25.jpg)

![20211201_154620](https://user-images.githubusercontent.com/20358075/144297328-330982b2-1f23-4b68-87c6-938d5ee2d0fb.jpg)


# Componentes utilizados
- 1 Cesto de lixo basculante;
- 1 Sensor ultrassónico HC-SR04;
- 1 NodeMcu ESP-8266 CH340G;
- 1 Micro Servo 9g SG90;
- 2 Protoboard 400 pontos;
- 1 Bateria 9v

# Especificação Técnica
O desenvolvimento do codigo foi utilizado a IDE Arduino e a linguagem C++. Para o desenvolvimento sistemico, fora utilizados as seguintes bibliotecas, disponiveis na IDE do Arduino:
* <Servo.h> - Biblioteca responsavel pelo acionamento e gerenciamento do componente Servo 9G;
* <AdafruitIO_WiFi.h> - Biblioteca responsavel por realizar a conexao via Wireless e tambem por conectar ao servidor AdaFruitIO, este que realiza a comunicacao via protocolo MQTT.

O acionamento remoto via protocolo MQTT foi realizado atraves do browser (Google Chrome), via site do AdafruitIO, este que disponibiliza um dashboard a ser montado conforme a demanda do projeto.

# Resultados Finais 

Após a conclusão tanto da montagem como do desenvolvimento do código, a comunicação via protocolo MQTT foi realizado com exito, mostrando que pode ser uma forma aliada nos desenvolvimentos em IoT, garantindo a execução rápida, eficaz e segura. 
