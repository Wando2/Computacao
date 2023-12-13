package lp2g25.biblioteca;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.List;

import lp2g25.biblioteca.exception.CopiaNaoDisponivelEx;
import lp2g25.biblioteca.exception.NenhumaCopiaEmprestadaEx;

public class Livro implements Serializable {
    private String codigoLivro;
    private String titulo;
    private ECategoriaLivro categoria;
    private int quantidade;
    private int emprestados;
    private List<EmprestPara> historico;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(
            "Codigo Livro: " + codigoLivro + "\n" +
            "Titulo: " + titulo + "\n" +
            "Categoria: " + categoria + "\n" +
            "Quantidade: " + quantidade + "\n" +
            "Emprestados: " + emprestados + "\n" +
            "Historico: " + "\n");
        
        if (historico.isEmpty()) {
            sb.append("\t").append("Nenhum empréstimo registrado").append("\n");
        } else {
             for (EmprestPara emprestPara : historico) {
             sb.append("\t").append(emprestPara.toString()).append("\n");
        }
        }

       

        return sb.toString();
    }

    public Livro(String codigoLivro, String titulo, String categoria, int quantidade) {
        this.codigoLivro = codigoLivro;
        this.titulo = titulo;
         try {
        this.categoria = ECategoriaLivro.valueOf(categoria);
        } catch (IllegalArgumentException e) {
        this.categoria = ECategoriaLivro.ROMANCE;
        }
        this.quantidade = quantidade;
        this.emprestados = 0;
        this.historico = new ArrayList<>();
    }    

    public void empresta() throws CopiaNaoDisponivelEx {
        if (quantidade > emprestados) {
            emprestados++;
        } else {
            throw new CopiaNaoDisponivelEx("Não há cópias disponíveis");
        }
    }

    public void devolve() throws NenhumaCopiaEmprestadaEx {
        if (emprestados > 0) {
            emprestados--;
        } else {
            throw new NenhumaCopiaEmprestadaEx("Não há cópias emprestadas");
        }
    }

    public void addUsuarioHist(GregorianCalendar dataEmprestimo, int codigoUsuario) {

       
        GregorianCalendar dataDevolucao = (GregorianCalendar) dataEmprestimo.clone();
        
  
        dataDevolucao.add(Calendar.DAY_OF_MONTH, 7);
        
        historico.add(new EmprestPara(dataDevolucao, codigoUsuario));
    }

    public String getCodigoLivro() {
        return codigoLivro;
    }

    public String getTitulo() {
        return titulo;
    }

    public ECategoriaLivro getCategoria() {
        return categoria;
    }

    public EmprestPara getEmprestParaByUsuario(Usuario usuario) {
        EmprestPara latestEmprestPara = null;
        for (EmprestPara emprestPara : historico) {
            if (emprestPara.getcodigoUsuario() == usuario.getCodigoUsuario() && (latestEmprestPara == null
                    || emprestPara.getDataEmprestimo().after(latestEmprestPara.getDataEmprestimo()))) {
                latestEmprestPara = emprestPara;
            }
        }
        return latestEmprestPara;
    }

}




