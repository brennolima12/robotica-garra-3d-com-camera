# **GARRA ROBÓTICA 3D COM CÂMERA PARA PODA DE ÁRVORES**
**Disciplina:** Elementos da Robótica  
**Universidade de Pernambuco (UPE)**  

---

## **EQUIPE**
- Brenno Lima
- Eduardo Távora
- Gabriel Agra
- Hugo Pinto
- Luca de Roldão
- Vitor Queiroz

---

## **DESCRIÇÃO DO PROJETO**
Este projeto consiste em uma **garra robótica impressa em 3D**, equipada com **câmera integrada** e controle eletrônico para **realizar podas precisas em galhos de árvores**.  
A proposta combina **mecânica e eletrônica**, aplicando os conceitos estudados na disciplina de Elementos da Robótica.

---

## **OBJETIVOS**
- Desenvolver um **mecanismo de garra funcional** capaz de segurar e cortar galhos finos.  
- Integrar **sensoriamento visual** para identificação da posição do galho.  
- Controlar o sistema por meio de **microcontrolador (ESP32)**.  

---

## **PRINCIPAIS COMPONENTES UTILIZADOS** 
- SeeedStudio XIAO ESP32-S3 Sense
- MG995 Servo Motor 
- MT3608 DC-DC Step-Up Module
- 18650 Battery
- Cabos, jumpers e suportes diversos  

---

## **FUNCIONALIDADES**
- Captura de imagem para auxílio na poda  
- Movimento de abertura e fechamento da garra  
- Corte automatizado de pequenos galhos  

---

| **Ferramenta**         | **Função no Projeto**                                                                 | **Integração com GitHub**                                                                 |
|-------------------------|------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| **CoppeliaSim**         | Simulação dos movimentos da garra, teste dos servos e verificação do corte virtual.      | Armazenar os **arquivos de simulação (.ttt)** no repositório para versionamento e reuso.  |
| **Autodesk Fusion 360** | Modelagem 3D das peças, montagem da garra e exportação para impressão e simulação.       | Salvar os **arquivos .f3d / .stl** em pastas do repositório (`/modelagem`), com versões.   |
| **Jira Software**       | Planejamento ágil das etapas: modelagem, eletrônica e simulação, com tarefas e prazos.   | Vincular **commits e pull requests** às issues do Jira para rastrear progresso automático. |


**Componentes** 

**Mini Disco de Serra** | Diâmetro de **50mm a 85mm** com pontas de **Carboneto de Tungstênio (TCT)**. |
**Motor DC de Alta Rotação** | Modelo **550** ou **775** (12V ou 24V), capaz de atingir **8.000 a 12.000 RPM** e potência próxima de **100W**. |
**Motoredutor DC com Redução** | Motor de 12V com caixa de redução metálica, torque de saída entre **10 kgf.cm e 20 kgf.cm** (RPM baixa, 25 a 150 RPM). |


---
Projeto desenvolvido durante o semestre **2025.2**, na disciplina **Elementos da Robótica** — **Universidade de Pernambuco (UPE)**.
