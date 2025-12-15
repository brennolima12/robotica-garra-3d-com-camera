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

## **COMPONENTES PRINCIPAIS** 

1. Simulação - CoppeliaSim
2. Simulação - Fusion 3D

https://github.com/user-attachments/assets/e14eaf50-cc1c-4a6d-a35d-46e369c8cb1d


https://github.com/user-attachments/assets/853c69ad-b97c-4bf9-adfa-8407e8c1bdd0


3. Simulação TinkerCard 


https://github.com/user-attachments/assets/cc6e9fef-9edf-44bb-b86a-1e4e483e3a38


4. Garra - Impressão 3D
<img width="1599" height="899" alt="image" src="https://github.com/user-attachments/assets/c47957f3-f47a-427b-bb88-b87302df0d94" />


5. Serra e Câmera



Estrutura Eletrônica
- Arduino Uno
- Esp32s3 Sense
- MG995 Servo Motor (180°)
- Motor DC
- Chave liga/desliga
- Fios de conexão 
- Resistores

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
