package ContentContext;

public class Homem extends PessoaIMC {
    
    public Homem(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura, long cpf) {

        super(nome, sobreNome, dia, mes, ano, peso, altura, cpf);

    }



    public Homem(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura) {

        super(nome, sobreNome, dia, mes, ano, altura, peso);

    }

    public Homem() {

        super();

    }

    @Override
    public String resultIMC() {
        float imc = calculaIMC();
        if (imc < 20.7) {
            return String.format("%.1f - Abaixo do peso ideal", imc);
        } else if (imc >= 20.7 && imc <= 26.4) {
            return String.format("%.1f - Peso ideal", imc);
        } else {
            return String.format("%.1f - Acima do peso ideal", imc);
        }
    }


}
