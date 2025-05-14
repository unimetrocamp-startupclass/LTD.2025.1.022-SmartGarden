# SmartGarden 🌱  
Sistema que auxilia o agricultor a monitorar sua plantação de maneira automática

## 👤 Dados do Cliente

- **Cliente:** Francisca Rodrigues Honorato  
- **CNPJ/CPF:** 287.524.448-56  
- **Contato:** (19) 98825-3800  
- **Email:** francisca.rodrigues@gmail.com

---

## 👨‍💻 Equipe de Desenvolvimento

| Nome                            | Curso                          | Disciplina                                 |
|-------------------------------|--------------------------------|--------------------------------------------|
| Gabriel Henrique de Oliveira Alves | Análise e Desenvolvimento de Sistemas | Programação Orientada a Objetos em Java |
| Gabriel Rodrigues Honorato        | Análise e Desenvolvimento de Sistemas | Programação Orientada a Objetos em Java |
| Isadora Geremias de Melo         | Análise e Desenvolvimento de Sistemas | Programação Orientada a Objetos em Java |

**Professor Orientador:** Prof. Kesede Rodrigues Julio

---

## 1. 📘 Introdução

O sistema visa automatizar o monitoramento ambiental das plantas, solucionando o problema de irrigação manual inadequada. Através de sensores físicos conectados a um Arduino, o sistema coleta dados de umidade e temperatura e os processa em uma aplicação c++, permitindo o acionamento automático da irrigação e visualização em tempo real.

---

## 2. 🎯 Objetivo

Automatizar o cuidado da horta monitorando a temperatura e umidade do solo, acionando automaticamente a irrigação em momentos adequados, reduzindo o desperdício de água e promovendo o crescimento saudável das plantas.

---

## 3. 📌 Escopo

### Requisitos:

- **Monitoramento:** Temperatura (DHT11) e umidade (FC-28).
- **Controle automático de irrigação:** Com base em janelas de horários pré-configuradas.
- **Interface:** Simples, via terminal/console.

### Fora do Escopo:

- Interface gráfica avançada
- Armazenamento de histórico
- Controle remoto via internet (IoT)

---

## 4. 📋 Backlogs do Produto

| Código | Requisito |
|--------|-----------|
| R1     | Monitorar Temperatura do Ambiente com sensor DHT11 |
| R2     | Monitorar Umidade do Solo com sensor FC-28 |
| R3     | Controlar Irrigação automaticamente com relé |
| R4     | Definir horários ideais para irrigação |
| R5     | Exibir dados em tempo real no console |

---

## 5. 📆 Cronograma

| Semana | Data                | Atividades |
|--------|---------------------|------------|
| 1      | 08 a 12 de abril    | Criar repositório e preencher README.md |
| 2      | 15 a 19 de abril    | Planejamento da lógica de sensores e início da codificação |
| 3      | 22 a 26 de abril    | Implementação dos sensores |
| 4      | 29 abr a 03 maio    | Irrigação automatizada e testes |
| 5      | 06 a 10 de maio     | Homologação interna e ajustes |
| 6      | 13 a 17 de maio     | Apresentação na Semana de Tecnologia |
| 7      | 20 a 24 de maio     | Preparação para FENETEC |
| 8      | 27 e 28 de maio     | Ajustes finais e entrega |

---

## 6. 🛠️ Materiais e Métodos
**Modelagem do Sistema**
1. Diagrama de Casos de Uso
Este diagrama apresenta as interações entre o ator (agricultor) e os principais processos do sistema.

Ator: Agricultor

Casos de Uso: Monitorar temperatura e umidade, Ativar irrigação automaticamente e Visualizar status em tempo real

Sugestão de ferramenta para criação: Draw.io (diagrams.net)

2. Diagrama de Classes (UML)
- Modelo baseado em programação orientada a objetos em c++, destacando a relação entre as principais classes do sistema:
- Sensor (classe abstrata)
- SensorTemperatura
- SensorUmidade
- ControladorIrrigacao
- Horta
- RelogioSistema (controla os horários de irrigação)
- MainApp (classe principal que orquestra o sistema)

**Tecnologias Utilizadas:**
> Tecnologia e	Descrição
c++ = Linguagem principal utilizada no desenvolvimento
Bibliotecas Arduino (DHT11, FC-28) = Leitura de dados dos sensores de temperatura e umidade
VsCode = Ambiente de desenvolvimento c++
Draw.io / LucidChart = Criação dos diagramas UML
GitHub = Controle de versão e documentação do projeto
Jira = Software	Gestão ágil das sprints e tarefas

**Arquitetura do Sistema**
Como o sistema é embarcado e envolve a integração entre hardware e software, sua arquitetura é dividida em três camadas principais:

|   Agricultor (Usuário)   | > | Interface Serial/Console | > 

+-----------------------------+
|   Agricultor (Usuário)      |
+-----------------------------+
           |
           v
+--------------------------------+
| Interface Serial/Console       |
+--------------------------------+
           |
           v
+------------------------------------+
|     Aplicação C++ (OOP)            |
| - Leitura dos sensores             |
| - Lógica de irrigação              |
| - Agendamento por horário          |
+------------------------------------+
           |
           v
+----------------------------------+
|      Arduino + Sensores          |
| - DHT11 (temperatura)            |
| - FC-28 (umidade)                |
| - Relé + bomba d’água            |
+----------------------------------+

**Fluxo das Informações:**
- Sensores enviam dados ao Arduino.
- Arduino transmite os dados via porta serial.
- Aplicação c++ interpreta os dados recebidos.
- Com base na lógica de irrigação, o sistema ativa a bomba d’água automaticamente, se necessário.
- O usuário pode visualizar o status do sistema em tempo real via console.

---

## 7. ✅ Resultados

-
a.	Protótipo: O protótipo inicial do sistema foi desenvolvido utilizando o Tinkercad para simulação e testes. Atualmente, o protótipo está sendo implementado em uma maquete física para validação em ambiente real, além que será apresentado na FENETEC.
 
b.	Códigos das principais funcionalidades: 
#include <LiquidCrystal.h>  // Biblioteca para comunicação com display LCD 16x2

int umi = 0;                       // Variável que armazena o valor da umidade do solo
const int relePin = 12;           // Pino digital conectado ao módulo relé (aciona a bomba)
LiquidCrystal lcd_1(0, 1, 2, 3, 4, 5);  // Pinos conectados ao LCD

void setup()
{
  pinMode(A0, INPUT);             // Configura o pino A0 como entrada (sensor de umidade FC-28)
  pinMode(relePin, OUTPUT);       // Configura o pino do relé como saída
  digitalWrite(relePin, HIGH);    // Desliga a bomba no início (relé em nível alto = desligado)
  lcd_1.begin(16, 2);             // Inicializa o LCD com 16 colunas e 2 linhas
}

void loop()
{
  umi = map(analogRead(A0), 0, 1023, 0, 100);  // Lê a umidade do solo e converte para escala de 0 a 100%

  lcd_1.setCursor(0, 0);       // Posiciona o cursor na primeira linha
  lcd_1.noAutoscroll();        // Evita rolagem automática do texto
  lcd_1.print("                "); // Limpa a linha
  lcd_1.setCursor(0, 0);       // Volta o cursor para o início

  if (umi <= 30) {                         // Se a umidade estiver baixa
    lcd_1.print("umidade baixa");         // Mostra alerta no LCD
    digitalWrite(relePin, HIGH);          // Liga a bomba (nível alto no relé)
  } else {
    lcd_1.print("umidade adequada");      // Mostra status normal
    digitalWrite(relePin, LOW);           // Desliga a bomba (nível baixo no relé)
  }

  delay(500);  // Aguarda 0,5 segundos antes da próxima leitura
}

---

## 8. ✅ Conclusão

a.	Impacto do sistema: O sistema auxilia no crescimento saudável das plantas, proporcionando um cuidado mais prático e eficiente para o agricultor.
b.	Melhorias Futuras: Implementar um sistema que envie atualizações em tempo real das condições do solo (temperatura e umidade) para o usuário.

---

## 9. 🧪 Homologação do MVP

O MVP foi apresentado e validado pelo cliente.  
(Fotos e lista de presença serão adicionadas no repositório.)

---

## 10. 📣 Divulgação

- **LinkedIn do Projeto:**  
  [Inserir link do perfil do projeto no LinkedIn aqui]

- **Apresentação no Seminário de Projetos de Software:**  
  [Inserir link do vídeo e fotos da apresentação]

- **FENETEC:**  
  [Inserir link do vídeo e fotos da feira]

---
