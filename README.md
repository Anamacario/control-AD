Projeto: Controle de LEDs RGB e Display com Joystick no RP2040

## 📌 Descrição

Este projeto implementa o controle de LEDs RGB e a exibição de um quadrado no display SSD1306 utilizando um joystick como entrada. O sistema é desenvolvido para a placa BitDogLab com o microcontrolador RP2040 e explora o uso de conversores Analógico-Digitais (ADC), interrupções e comunicação via I2C.

## 🎯 Funcionalidades

- O projeto permite o controle de LEDs RGB por meio de PWM, onde o brilho do LED Azul é ajustado conforme a posição do eixo Y do joystick e o brilho do LED Vermelho é ajustado conforme a posição do eixo X, ambos apagados na posição central e atingindo o brilho máximo nos extremos. Além disso, um quadrado de 8x8 pixels é exibido no display SSD1306 e se move de acordo com a posição do joystick. O botão do joystick alterna o estado do LED Verde e modifica a borda do display, enquanto o botão A ativa ou desativa os LEDs RGB controlados por PWM. O sistema utiliza interrupções para detectar pressionamentos dos botões e inclui debouncing via software para evitar acionamentos indesejados.

## 🛠 Requisitos

- Raspberry Pi Pico W 
- Joystick analógico
- LED RGB
- Placa BitDogLab
- Display OLED SSD1306

- **Ferramentas:**
  - SDK do Raspberry Pi Pico
  - Editor de código **VS Code**
  - CMake e Ninja para compilação

## 📌 Configuração dos Pinos

| Componente            | GPIO                          |
| --------------------- | ----------------------------- |
| LED RGB Azul          | GPIO 12                       |
| LED RGB Vermelho      | GPIO 11                       |
| Joystick X            | GPIO 26                       |
| Joystick Y            | GPIO 27                       |
| Botão do Joystick     | GPIO 22                       |
| Botão A               | GPIO 5                        |
| Display SSD1306 (I2C) | GPIO 14 (SDA) / GPIO 15 (SCL) |

## 🚀 Como Executar
1. **Clonar o repositório**
   ```bash
   git clone https://github.com/Anamacario/control-AD.git
   cd control-AD
   ```
2. **Compilar e carregar no Raspberry Pi Pico**
   - Conectar a placa ao computador
   - Compilar o código e copiar o arquivo `.uf2` para a bitdoglab

 ##  🔍 Testes Realizados

✅ Ajuste progressivo de brilho dos LEDs conforme o joystick
✅ Movimentação do quadrado no display proporcional ao joystick
✅ Troca do estado do LED Verde ao pressionar o botão do joystick
✅ Modificação da borda do display ao pressionar o botão do joystick
✅ Ativa/desativa os LEDs com o botão A

## 🎥 Entrega e Demonstração

1. **Código-fonte**: Disponível no repositório GitHub com documentação e organização.
2. **Vídeo Demonstrativo**:
   - Demonstração em execução na placa **BitDogLab**.
   - Click [AQUI](https://drive.google.com/file/d/1BaSOSi4oXq9D6jD6oMEd57zU1nXax7C1/view?usp=sharing) para acessar o link do vídeo de apresentação.
