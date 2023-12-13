package lp2g25.biblioteca;

import java.util.GregorianCalendar;
import java.io.Serializable;
import java.util.Calendar;

public class Pessoa implements Serializable {
    private String nome;
    private String sobreNome;
    private GregorianCalendar dataNascimento;
    private float altura;
    private float peso;
    
   
    private static int totalPessoas = 0;

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano) {
        this.nome = nome;
        this.sobreNome = sobreNome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        totalPessoas++;
    }

    public Pessoa(String nome, String sobreNome, int dia, int mes, int ano, float altura, float peso ) {
        this(nome, sobreNome, dia, mes, ano);
        this.peso = peso;
        totalPessoas++;
    }

    public Pessoa() {
        totalPessoas++;
    }

    public void setNome(String nome) throws IllegalArgumentException {
        if (nome.length() > 30) {
            throw new IllegalArgumentException("Nome muito grande");
        }
        this.nome = nome;
    }

    public void setSobreNome(String sobreNome) throws IllegalArgumentException {
        if (sobreNome.length() > 30) {
            throw new IllegalArgumentException("Sobrenome muito grande");
        }
        this.sobreNome = sobreNome;
    }

    public void setDataNascimento(int dia, int mes, int ano) throws IllegalArgumentException {
        if (ano <= 1900 || ano >= 2020) {
            throw new IllegalArgumentException("Ano inválido");
        }
        
        if (mes <= 0 || mes >= 13) {
            throw new IllegalArgumentException("Mês inválido");
        }

        if (dia <= 0 || dia >= 32) {
            throw new IllegalArgumentException("Dia inválido");
        }

        dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
    }

    public void setAltura(float altura) throws IllegalArgumentException {
        if (altura <= 0) {
            throw new IllegalArgumentException("Altura inválida");
        }
        if (altura > 0 && altura < 3) {
            this.altura = altura;
        } else if (altura > 3 && altura < 300) {
            this.altura = altura / 100;
        } else {
            throw new IllegalArgumentException("Altura inválida");
        }
    }

    public void setPeso(float peso) throws IllegalArgumentException {
        if (peso <= 0) {
            throw new IllegalArgumentException("Peso inválido");
        }
        if (peso > 0 && peso < 300) {
            this.peso = peso;
        } else {
            throw new IllegalArgumentException("Peso inválido");
        }
    }

    public static void incrementarPessoa() {
        totalPessoas++;
    }

    // getter

    public String getNome() {
        return nome;
    }

    public String getSobreNome() {
        return sobreNome;
    }

    public GregorianCalendar getDataNascimento() {
        return dataNascimento;
    }

    public float getAltura() {
        return altura;
    }

    public float getPeso() {
        return peso;
    }


    public static int numPessoas() {
        return totalPessoas;
    }

    public int calcularIdade() {
        Calendar hoje = Calendar.getInstance();
        int idade = hoje.get(GregorianCalendar.YEAR) - dataNascimento.get(GregorianCalendar.YEAR);

        return idade;

    }

    public String toString() {
        String dados = "Nome: " + nome + " " + sobreNome + "\nData de Nascimento: "
                + dataNascimento.get(GregorianCalendar.DAY_OF_MONTH) + "/"
                + (dataNascimento.get(GregorianCalendar.MONTH) + 1) + "/" + dataNascimento.get(GregorianCalendar.YEAR) + "\nIdade: " + calcularIdade() + "\nGenero: " + getClass().getName();
        
       if(altura > 0){
         dados += "\nAltura: " + altura;
       }

       if(peso > 0){
           dados += "\nPeso: " + peso;
       }

       
      return dados;
    }

}