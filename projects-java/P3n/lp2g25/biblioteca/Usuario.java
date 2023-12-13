package lp2g25.biblioteca;

import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.List;

public class Usuario extends Pessoa implements java.io.Serializable{
  private int codigoUsuario;
  private static int incrementoCodigoUsuario = 1;
  private String Endereco;
  private List<Emprest> historico;

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();

    sb.append(
            "Nome: " + getNome() + " " + getSobreNome() + "\n" +
            "Idade: " + calcularIdade() + "\n" +
            "Codigo Usuario: " + codigoUsuario + "\n" +
            "Endereco: " + Endereco + "\n" +
            "Historico: " + "\n");

    if (historico.isEmpty()) {
      sb.append("\t").append("Nenhum empréstimo registrado").append("\n");
    }
    
    else {
      for (Emprest emprest : historico) {
        sb.append("\t").append(emprest.toString()).append("\n");
      }
    }

    return sb.toString();

  }

  public Usuario(String nome, String sobreNome, int dia, int mes, int ano, String Endereco) {
    super(nome, sobreNome, dia, mes, ano);
    this.Endereco = Endereco;
    historico = new ArrayList<>();
    codigoUsuario = incrementoCodigoUsuario++;
  }

  public Usuario(String nome, String sobreNome, int dia, int mes, int ano, float altura, float peso, String Endereco) {
    super(nome, sobreNome, dia, mes, ano, altura, peso);
    this.Endereco = Endereco;
    historico = new ArrayList<>();
    codigoUsuario = incrementoCodigoUsuario++;
  }

  public Usuario() {
    super();
    historico = new ArrayList<>();
    codigoUsuario = incrementoCodigoUsuario++;
  }

  public int getCodigoUsuario() {
    return codigoUsuario;
  }

  public String getEndereco() {
    return Endereco;
  }

  public void setEndereco(String Endereco) {
    this.Endereco = Endereco;
  }

  public List<Emprest> getHistorico() {
    return historico;
  }

  public void addLivroHist(GregorianCalendar dataEmprestimo, String codigoLivro) {
    historico.add(new Emprest(dataEmprestimo, codigoLivro));
  }

  public Emprest getEmprestLivro(Livro livro) {
    Emprest latestEmprest = null;
    for (Emprest emprest : historico) {
      if (emprest.getCodigoLivro().equals(livro.getCodigoLivro())
          && (latestEmprest == null || emprest.getDataEmprestimo().after(latestEmprest.getDataEmprestimo()))) {
        latestEmprest = emprest;
      }
    }
    return latestEmprest;
  }

}
