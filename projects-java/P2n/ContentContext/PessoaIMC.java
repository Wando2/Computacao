package ContentContext;

import ValidationContext.ValidaCPF;

public abstract class PessoaIMC extends Pessoa {

    protected float peso;
    protected float altura;

    public PessoaIMC(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura, long cpf) {
        super(nome, sobreNome, dia, mes, ano,cpf);
        this.peso = peso;
        this.altura = altura;
    }

    public PessoaIMC(String nome, String sobreNome, int dia, int mes, int ano, float peso, float altura) {
        super(nome, sobreNome, dia, mes, ano);
        this.peso = peso;
        this.altura = altura;
    }

    public PessoaIMC() {
        super();
    }

    protected float calculaIMC() {
        return (float) (peso / (altura * altura));
    }
    
    public abstract String resultIMC();


    @Override
    public String toString() {
        return "\n" + "Nome: " + nome + " " + sobreNome + "\n" +
                "CPF: " + ValidaCPF.imprimeCPF(String.valueOf(cpf)) + "\n" +
                "Idade: " + calcularIdade() + "\n" +
               "Data de Nascimento: " + getDataNascimento() + "\n" +
               "Peso: " + peso + "kg\n" +
                "Altura: " + altura + "m\n" +
                "Genero: " + getGenero() + "\n" +
               "Resultado IMC: " + resultIMC(); 
    }


    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        try {
            if (peso > 0) {
                this.peso = peso;
            } else {
                throw new IllegalArgumentException("Peso invalido");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        try {
            if (altura > 0) {
                this.altura = altura;
            } else {
                throw new IllegalArgumentException("Altura invalida");
            }
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

}