import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


// Define public class Graph 

public class Graph {
    // blank 2D array matrix declared
    private int adjacencyMatrix[][]=null;

    // instructions array
    private List<String> instructions= new ArrayList<String>();
    private List<String> sections= new ArrayList<String>();

    // 
    private void fillmatrix(String arch){
        try (BufferedReader br = new BufferedReader(new FileReader(arch))) {
            String line;
            int rows = 0;

            // Leer la matriz del archivo linea por linea
            while ((line = br.readLine()) != null) {
                String[] values = line.trim().split("\\s+");
                if (adjacencyMatrix == null) {
                    // Initialize the adjacency matrix based on the first line
                    int columns = values.length;
                    adjacencyMatrix = new int[columns][columns];
                }

                // Llenar matriz del grafo
                for (int j = 0; j < values.length; j++) {
                    adjacencyMatrix[rows][j] = Integer.parseInt(values[j]);
                }

                rows++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    // Cosnstructor --> Graph
    public Graph(String arch){
        fillmatrix(arch);
        initializeGraph();
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    // clases auxiliares --> Nodos y Lados
    private class Node {
        
        private String name;
        private List<Node> linkedNodes= new ArrayList<Node>();

        public Node(String name_ ){
            name=name_;
        }
        public String getName(){
            return name;
        }
    }

    private class Side {
        private String name;
        private Node n1, n2;
    
        // Constructor with a name parameter
        public Side(Node node1, Node node2, String name_) {
            n1 = node1;
            n2 = node2;
            name = name_;
        }

        public Node getNode1(){
            return n1;
        }
        public Node getNode2(){
            return n2;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Instancia de listas para Nodos y Lados
    private List<Node> nodes= new ArrayList<Node>();
    private List<Side> sides= new ArrayList<Side>();
    private List<Node> forks= new ArrayList<Node>();
    private List<Node> joins= new ArrayList<Node>();
    //////////////////////////////////////////////////////////////////////////////////////////////
    // Metodos

    public void showmatrix(){
        //Matrix
        for(int i=0; i<adjacencyMatrix.length; i++){
            for(int j=0; j<adjacencyMatrix.length; j++){
                System.out.print(adjacencyMatrix[i][j]);
            }
            System.out.println("");
        }
    }
    
    public void integrateNode(Node node){
        nodes.add(node);
    }

    public void integrateSide(Side side){
        sides.add(side);
    }

    public void deleteNode(Node node){
        for(Node n : nodes){
            if(n.name == node.name){
                int index = nodes.indexOf(n);
                nodes.remove(index);
            }
        }
    }

    public void deleteSide(Side side){
        for(Side s : sides){
            if(s.n1 == side.n1 && s.n2 == side.n2){
                int index = sides.indexOf(s);
                sides.remove(index);
            }
        }
    }
    
    private void initializeGraph(){
        // Create Nodes
        for(int i=1; i< adjacencyMatrix.length+1; i++) {
            Node n = new Node("S"+Integer.toString(i));
            this.integrateNode(n) ;
        }

        int sideCounter = 1;
        // Create Sides
        for(int nodey = 0; nodey < adjacencyMatrix.length; nodey++) {
            for(int nodex = 0; nodex < adjacencyMatrix.length; nodex++) {
                if (adjacencyMatrix[nodex][nodey] == 1) {
                    Node n1 = new Node("S" + Integer.toString(nodex + 1 ));
                    Node n2 = new Node("S" + Integer.toString(nodey + 1 ));
                    
                    // Generate a unique name for the side, e.g., "L1"
                    String sideName = "L" + sideCounter++;
                    
                    Side side = new Side(n1, n2, sideName);
                    this.integrateSide(side);
                }
            }
        }
    }
    
    // HashMap to store counts of nodes on the left side
    private Map<String, Integer> leftNodeCounts = new HashMap<>();
    private Map<String, Integer> RightNodeCounts = new HashMap<>();

    public void ForkandJoinAnalize() {
        // Loops through all the "side objects from the list Sides"
        System.out.println("\nSides:");
        for (Side side : sides) {
            // Displays the two nodes connected to the sides
            System.out.println(side.n1.name + " -- " + side.name + " -- " + side.n2.name);

            // Update counters based on the nodes on the left side
            // "Regex" stands for "regular expression,"
            if (side.n1.name.matches("S\\d+")) {
                //if the Node 1 name matches the regular expression, then it adds one with an inital value of 0
                leftNodeCounts.put(side.n1.name, leftNodeCounts.getOrDefault(side.n1.name, 0) + 1);
            }

            if (side.n2.name.matches("S\\d+")) {
                //if the Node 2 name matches the regular expression, then it adds one with an inital value of 0
                RightNodeCounts.put(side.n2.name, RightNodeCounts.getOrDefault(side.n2.name, 0) + 1);
            }
        }

        // Display left node counts
        System.out.println("\n Forks:");
        // loops over the keys of leftnodecounts map
        for (String nodeName : leftNodeCounts.keySet()) {
            // displays the node + its value 
            if (leftNodeCounts.get(nodeName) > 1 ){
                for(Node node: nodes){
                    if(node.getName().equalsIgnoreCase(nodeName)){
                        forks.add(node);
                    }
                }
                System.out.println(nodeName + ": " + leftNodeCounts.get(nodeName));
            }
                
        }

        System.out.println("\n Joins:");
        // loops over the keys of leftnodecounts map
        for (String nodeName : RightNodeCounts.keySet()) {
            // displays the node + its value 
            if (RightNodeCounts.get(nodeName) > 1 ){
                for(Node node: nodes){
                    if(node.getName().equalsIgnoreCase(nodeName)){
                        joins.add(node);
                    }
                }
                System.out.println(nodeName + ": " + RightNodeCounts.get(nodeName));
                instructions.add("CONT-"+nodeName + ": " + RightNodeCounts.get(nodeName)); // add initial node CONTS  to instructions
            }
        }
        print("\n\n\n");

    }

    private void showinstructions(){
        System.out.println("\n\nPseudocodigo FORK/JOIN: ==============");
        for(String inst : instructions){
            if(inst == instructions.get(instructions.size()-1)){
                for(String section : sections){
                    System.out.println(section);
                }
                System.out.println(inst);
            }else{
                System.out.println(inst);
            } 
        }
    }

    private List<Node> getlinkedNodes(Node node){
        List<Node> linkedNodes = new ArrayList<Node>();
        for(Side side: sides){
            if(side.getNode1().getName().equalsIgnoreCase(node.getName())){
                linkedNodes.add(side.getNode2());
            }
        }
        return linkedNodes;
    }

    private List<Node> getBackNodes(Node node){
        List<Node> backnodes = new ArrayList<Node>();
        for(Side side: sides){
            if(side.getNode2().getName().equalsIgnoreCase(node.getName())){
                backnodes.add(side.getNode1());
            }
        }
        return backnodes;
    }

    private void addSection(String newinstruction, String sectionedinstruction){
        char section = 'L';
        int aux = 0;
        for(String instruction: instructions){
            if( instruction.charAt(instruction.length()-2) == section){
                int aux1 = Integer.parseInt(String.valueOf(instruction.charAt(instruction.length()-1)));
                aux= aux1+1;
            }
        }
        if(aux==0){
            aux=1;
        }
        String sectionL = newinstruction+" L"+aux;
        String straux= "L"+aux+": "+sectionedinstruction;
        boolean exist = false;

        for(String inst: sections){
            if(inst.contains(sectionedinstruction)){
                exist=true;
            }
        }
        if(!exist){
            
            instructions.add(sectionL);
            sections.add( straux);
        }
        
    }

    public boolean checkin(List<Node> lista, Node node ){
        boolean exist= false;
        for(Node node_: lista){
            if(node_.getName().equalsIgnoreCase(node.getName())){
                exist=true;
            }
        }
        return exist;
    }

    public boolean checkin(List<String> lista, String str ){
        boolean exist= false;
        for(String str_: lista){
            if(str_.equalsIgnoreCase(str)){
                exist=true;
            }
        }
        return exist;
    }

    private boolean initial=true;
    private boolean terminal=false;
    private boolean finished=false;
    private int cont_pend_node=0;
    private List<Node> joinsDone= new ArrayList<Node>();
    private List<Node> forksDone= new ArrayList<Node>();
    private List<Node> indivDone= new ArrayList<Node>();

    private void loop(Node node){
        print("Nodo actual "+node.getName()+"=================");
        if(!finished){
            

            //Check if current node is TERMINAL
            if(getlinkedNodes(node).size()==0){
                // Node --> TERMINAL
                terminal=true;
            }

            //FORKS
            if(checkin(forks, node)){
                // nodo -> fork
                if(!checkin(forksDone, node)){
                    // fork no ejecutado
                    forksDone.add(node);
                    if(initial){
                        initial=false;
                    }else{
                        print("FORK"+node.getName());
                        //instructions.add(node.getName());
                    }
                    
                    boolean itfork=false;
                    for(Node lknode: getlinkedNodes(node)){ // Loop to section
                        if(!itfork){
                            // Skip left element
                            itfork=true;
                        }else{
                            // Section right elements 
                            if(checkin(joins, lknode)){
                                addSection("Fork", "JOINT CONT-"+lknode.getName());
                                joinsDone.add(lknode);
                                
                            }else{
                                addSection("Fork", lknode.getName());
                                
                            }  
                        }
                        
                    }
                    // Recursive loop
                    for(Node lknode: getlinkedNodes(node)){ // Loop to section
                        print("exe FORK "+node.getName()+" - "+lknode.getName());
                        loop(lknode);
                    }
                    
                    //Fork finished
                }
                //else : Loop ejecutado
            }

            // Join
            if(checkin(joins, node)){
                // Node->join
                print("JOIN"+node.getName());
                print("JOIN"+node.getName()+" TERMINAL = "+terminal);
                print("Executed? "+checkin(joinsDone, node));
                if(!checkin(joinsDone, node)){
                    //Join no ejecutado
                    addSection("GOTO", "JOINT CONT-"+node.getName());
                    
                    if(!terminal){
                        joinsDone.add(node);
                        //Joins no terminales
                        // probamos return ========================
                        terminal=false;
                        
                        return;
                        
                    }else{
                        //Join Terminal
                        joinsDone.add(node);
                        if(cont_pend_node==getBackNodes(node).size()){
                            //Pending nodes completed
                            finished=true;
                            print("TERMINOOOOOOOOOOOOOOOOO");
                            //FINISH GRAPH
                            
                        }  
                        return;    
                    }
                }else{
                    //Joins individuales
                    if(terminal){
                        
                        cont_pend_node++;
                        if(initial){
                            initial=false;
                        }else{
                            if(!checkin(indivDone, node)){
                                print("Join individual "+node.getName()+" - ");
                                instructions.add(node.getName());
                                indivDone.add(node);
                            }
                        }
                        for(Node lknode: getlinkedNodes(node)){
                            
                            loop(lknode);
                        }
                        return;
                        
                    }else{
                        for(Node lknode: getlinkedNodes(node)){
                            if(initial){
                                initial=false;
                            }else{
                                if(!checkin(indivDone, node)){
                                    print("2Join individual "+node.getName()+" - "+lknode.getName());
                                    instructions.add(node.getName());
                                    indivDone.add(node);
                                }
                            }
                            loop(lknode);
                        }
                        return;
                    }
                    
                }
            }

            // Individual
            if(getlinkedNodes(node).size()==1 && !terminal){
                // Node -> Idividual
                if(initial){
                    initial=false;
                }else{
                    if(!checkin(indivDone, node)){
                        print("1Individual"+node.getName());
                        instructions.add(node.getName());
                        indivDone.add(node);
                    }
                }
                for(Node lknode: getlinkedNodes(node)){
                    loop(lknode);
                }
                
                return;
                
            }
            if(getlinkedNodes(node).size()==1 && terminal){
                if(initial){
                    initial=false;
                }else{
                    if(!checkin(indivDone, node)){
                        print("1Individual"+node.getName());
                        instructions.add(node.getName());
                        indivDone.add(node);
                    }
                }
                //loop(lknode);
                for(Node lknode: getlinkedNodes(node)){
                    loop(lknode);
                    
                }
                return;
            }
            
        } 
    }

    public void analyzeGraph(){
        instructions.add(nodes.get(0).getName()); // add root to instructions
        this.ForkandJoinAnalize();
        indivDone.add(nodes.get(nodes.size()-1));
        loop(nodes.get(0));   
        instructions.add(nodes.get(nodes.size()-1).getName()); // add terminal node to instructions
        this.showinstructions();
    }

    private void print(String msg){
        System.out.println(msg);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Main
    public static void main(String[] args){
        //sList<String> archs = new ArrayList<String>();
        //archs.add("graph1.txt");
        String arch= "graph3.txt";
        System.out.println((arch+"======================================"));
        Graph myGraph = new Graph(arch);
        myGraph.analyzeGraph();
        System.out.println(("END "+arch+"======================================\n\n"));
        
    } 
}



