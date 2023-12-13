import java.util.Scanner;
import ContentContext.Homem;
import ContentContext.MinhaListaOrdenavel;
import ContentContext.Mulher;

public class P2nX {
    public static void main(String[] args) {

        MinhaListaOrdenavel minhaLista = new MinhaListaOrdenavel();

       

        minhaLista.addPessoa(new Homem("Joao", "Silva", 1, 1, 1990, 1.80f, 50f, 68808746062L));
        minhaLista.addPessoa(new Homem("Paulo", "Costa", 1, 1, 1980, 40f, 1.8f, 31572932066L));
        minhaLista.addPessoa(new Homem("Pedro", "Fernadez", 2, 2, 1985, 75f, 1.75f, 95596345008L));
        minhaLista.addPessoa(new Homem("Lucas", "Dias", 3, 3, 1990, 80f, 1.85f, 67695241040L));
        minhaLista.addPessoa(new Homem("Fernando", "Santos", 4, 4, 1995, 85f, 1.9f, 28860331030L));   
        minhaLista.addPessoa(new Mulher("Maria", "Rocha", 5, 5, 1980, 90f, 1.6f, 13257915047L));
        minhaLista.addPessoa(new Mulher("Ana", "Souza", 6, 6, 1985, 45f, 1.65f, 61975688023L));
        minhaLista.addPessoa(new Mulher("Carla", "Oliveira", 7, 7, 1990, 70f, 1.75f, 72845168012L));
        minhaLista.addPessoa(new Mulher("Julia", "Lima", 8, 8, 1995, 120f, 1.6f, 27149968090L));
        minhaLista.addPessoa(new Mulher("Larissa", "Ferreira", 9, 9, 2000, 65f, 1.7f, 51319294073L));
        
        Scanner scanner = new Scanner(System.in);
        

    while (true) {
        System.out.println("1. Imprimir Lista");
        System.out.println("2. Sair");
        System.out.print("Digite sua opcao: ");
        int opcao = scanner.nextInt();
        System.out.println();

        switch (opcao) {
            case 1:
                System.out.println("Escolha seu modo de ordenacao");
                System.out.println("1. Peso");
                System.out.println("2. Altura");
                System.out.println("3. IMC");
                System.out.println("4. Nome (A-Z)");
                System.out.println("5. Nome (Z-A)");
                System.out.println("6. Genero");
                System.out.print("Digite sua opcao: ");
                int ordenacao = scanner.nextInt();

                minhaLista.ordena(ordenacao);
                System.out.println(minhaLista.toStringAll());
                break;

            case 2:
                System.out.println("Saindo...");
                scanner.close();
                System.exit(0);

            default:
                System.out.println("Opcao invalida. Tente novamente.");
        }
    }
}
        
    

}