#!/usr/bin/env python
# coding: utf-8

# In[70]:


import networkx as nx

G = nx.Graph()

id = 0          #posição do nucleotídeo na sequência
lastPr = 0      #pega a posição do último parênteses encontrado
max = 0         #0 até até que se chegue em um ")"

nodecolor = list()    #cores dos vértices
labels  = {}          #nucleotídeo


seq = "GGCUUCCUGGUACUUACCACAGUCUGUAUUCUUACACUGACUGUAUAGAAAGAGGAGGC"
dbn = ".(((((((....((....((((((((((....))))..))))))..))....)))))))"

for i in dbn:    
    if len(seq) != len(dbn):
        print ("numero de vertices invalido")        
    else:        
        if i != ")" and max == 0:        #caso ainda não tenha chegado em ")"            
            G.add_node(id)               #adiciona o vértice atual
            nucleotides[id] = seq[id]    #define o label
            G.add_edge(id, id+1)         #adiciona a aresta que liga o atual com o próximo
            
            if i != ".":                         #caso não seja um vértice 'não pareado'
                G.node[id]['color']='purple'     #define a cor
                nodecolor.append('purple')
                lastPr = id                      #define a posição do último "(" encontrado 
            else:
                G.node[id]['color']='c'
                nodecolor.append('c')
                
            id = id+1                    #próximo vértice
            
        else:
            max = 1;                     #chega em ")"
            
            G.add_node(id)               #adiciona o vértice atual
            nucleotides[id] = seq[id]    #define o label
            G.add_edge(id, id+1)         #adiciona a aresta que liga o atual com o próximo
            
            if i != ".":                        #caso não seja um vértice 'não pareado'
                G.node[id]['color']='purple'    #define a cor
                nodecolor.append('purple')
                
                while dbn[lastPr] == ".":       #caso dbn na posição lastPr seja um "."
                    lastPr = lastPr-1           #decrementa lastPr
                    
                if dbn[lastPr] == "(":          #caso dbn na posição lastPr seja um "("
                    G.add_edge(lastPr,id)       #adiciona a aresta que liga o vértice dbn[lastPr] com o vértice atual   
                    lastPr = lastPr-1;     
            else:                               #caso seja um vértice 'não pareado'
                G.node[id]['color']='c'         #define a cor
                nodecolor.append('c')
            
            id = id+1                   #próximo vértice
            
G.remove_node(id)   #remove o último vértice adicionado pois ele não existe na sequência original, ...
                    #foi criado a partir a incrementação de id na linha anterior

#Desenha a representação em grafos da estrutura secundária correspondente
nx.draw(G, labels = nucleotides, pos = nx.circular_layout(G), with_labels = True, node_color = nodecolor)
plt.show()

#imagem da saída no formato .png
plt.savefig("TdG_ex2.png")


# In[ ]:




