# 🌿 **GARRA ROBÓTICA 3D COM CÂMERA PARA PODA DE ÁRVORES**
**Disciplina:** Elementos da Robótica  
**Universidade de Pernambuco (UPE)**  

---

## 👨‍🔧 **EQUIPE**
- Brenno Lima
- Eduardo Távora
- Gabriel Agra
- Hugo Pinto
- Luca de Roldão
- Vitor Queiroz

---

## 🧠 **DESCRIÇÃO DO PROJETO**
Este projeto consiste em uma **garra robótica impressa em 3D**, equipada com **câmera integrada** e controle eletrônico para **realizar podas precisas em galhos de árvores**.  
A proposta combina **mecânica e eletrônica**, aplicando os conceitos estudados na disciplina de Elementos da Robótica.

---

## ⚙️ **OBJETIVOS**
- Desenvolver um **mecanismo de garra funcional** capaz de segurar e cortar galhos finos.  
- Integrar **sensoriamento visual** para identificação da posição do galho.  
- Controlar o sistema por meio de **microcontrolador (ESP32)**.  

---

## 🧩 **PRINCIPAIS COMPONENTES UTILIZADOS** 
- SeeedStudio XIAO ESP32-S3 Sense
- MG995 Servo Motor 
- MT3608 DC-DC Step-Up Module
- 18650 Battery
- Cabos, jumpers e suportes diversos  

---

## 💡 **FUNCIONALIDADES**
- Captura de imagem para auxílio na poda  
- Movimento de abertura e fechamento da garra  
- Corte automatizado de pequenos galhos  

---

**Ferramentas**
⚙️ Definição da Solução de Corte

**Serra Rotativa (Mini-Disco de Serra).**
    * **Motivação:** Oferece cortes mais rápidos e limpos, além de gerar cargas de reação mais uniformes e controláveis, sendo mais adequada para estruturas impressas em 3D, que são sensíveis a cargas cíclicas de alto impacto (vibração).

**Estimativa de Torque e Energia:**
    * **Torque (T):** Essencial para superar a resistência da madeira. Um ponto de partida sugerido para o motor de corte é entregar entre **0.5 Nm a 2.0 Nm** no eixo da serra (considerando galhos de 10mm a 25mm).
    * **Potência (P):** A potência (energia) para manter a velocidade de corte é sugerida na faixa de **50W a 150W**.

**Componentes** 

**Mini Disco de Serra** | Diâmetro de **50mm a 85mm** com pontas de **Carboneto de Tungstênio (TCT)**. |
**Motor DC de Alta Rotação** | Modelo **550** ou **775** (12V ou 24V), capaz de atingir **8.000 a 12.000 RPM** e potência próxima de **100W**. |
**Motoredutor DC com Redução** | Motor de 12V com caixa de redução metálica, torque de saída entre **10 kgf.cm e 20 kgf.cm** (RPM baixa, 25 a 150 RPM). |


---
Projeto desenvolvido durante o semestre **2025.2**, na disciplina **Elementos da Robótica** — **Universidade de Pernambuco (UPE)**.
