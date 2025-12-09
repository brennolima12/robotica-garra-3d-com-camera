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

---

## **PRINCIPAIS COMPONENTES UTILIZADOS** 
Estrutura Eletrônica
- SeeedStudio XIAO ESP32-S3 Sense
- MG995 Servo Motor (180°)
- Servo adapter (impresso em 3D)
- MT3608 DC-DC Step-Up Module
- Suporte para 1 bateria 18650 (1s)
- Bateria 18650 recarregável
- Chave liga/desliga
- Fios de conexão 
- Resistores de 15 Ω
- LEDs brancos de 5 mm
  
Estrutura Mecânica
- Peças impressas em 3D baseadas no modelo Cam Claw (podendo ser impressas novamente ou reaproveitadas de outros projetos)
- Parafusos M3 x 20 mm
- Parafusos M3 x 4 mm
- Parafusos M4 x 20 mm
- Parafusos 1/4 x 20 mm
- Tubo de PVC 25 mm
- Cola multiuso / supercola
- Suporte para celular 


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


---
Projeto desenvolvido durante o semestre **2025.2**, na disciplina **Elementos da Robótica** — **Universidade de Pernambuco (UPE)**.
