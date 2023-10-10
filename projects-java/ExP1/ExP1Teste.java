
public class ExP1Teste {
    
    public static void main(String[] args){
        Pessoa[] pessoas = new Pessoa[3];

        pessoas[0] = new Pessoa("Joao");
        pessoas[1] = new Pessoa("Caio", "Costa", 1960, 1, 30, 180, 80, 'M', null, null, "vivo");
        pessoas[2] = new Pessoa("Maria", "Silva", 1950, 11, 04, 160, 50, 'f', null, null, "morreu");

        pessoas[0].setSobrenome("Costa");
        pessoas[0].setAltura(170);
        pessoas[0].setPeso(70);
        pessoas[0].setGenero('M');
        pessoas[0].setMae(pessoas[2]);
        pessoas[0].setPai(pessoas[1]);
        pessoas[0].setStatus("vivo");
        pessoas[0].setDataNascimento(1990, 12, 12);




        System.out.println(pessoas[0].toString());

        System.out.println("Nº de pessoas: " + Pessoa.getContadorPessoas());

       
        

    }

}