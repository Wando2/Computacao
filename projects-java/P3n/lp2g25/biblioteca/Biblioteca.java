package lp2g25.biblioteca;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.GregorianCalendar;
import java.util.Hashtable;
import java.util.List;
import lp2g25.biblioteca.exception.CopiaNaoDisponivelEx;
import lp2g25.biblioteca.exception.LivroNaoEncontradoEx;
import lp2g25.biblioteca.exception.NenhumaCopiaEmprestadaEx;
import lp2g25.biblioteca.exception.TipoDeArquivoInvalidoEx;
import lp2g25.biblioteca.exception.UsuarioNaoEncontradoEx;

public class Biblioteca  {
    private Hashtable<Integer, Usuario> cadastroUsuarios;
    private Hashtable<String, Livro> cadastroLivros;

    public Biblioteca() {
        cadastroUsuarios = new Hashtable<>();
        cadastroLivros = new Hashtable<>();
    }

    public Biblioteca(String arquivoUsuarios, String arquivoLivros) throws IOException, ClassNotFoundException {
        ObjectInputStream oisUsuarios = new ObjectInputStream(new FileInputStream(arquivoUsuarios));
        ObjectInputStream oisLivros = new ObjectInputStream(new FileInputStream(arquivoLivros));

        cadastroUsuarios = (Hashtable<Integer, Usuario>) oisUsuarios.readObject();
        cadastroLivros = (Hashtable<String, Livro>) oisLivros.readObject();

        oisUsuarios.close();
        oisLivros.close();
    }

    public void addUsuario(Usuario usuario) {
        cadastroUsuarios.put(usuario.getCodigoUsuario(), usuario);
    }

    public void addLivro(Livro livro) {
        cadastroLivros.put(livro.getCodigoLivro(), livro);
    }

    public Livro getLivro(String codigoLivro) throws LivroNaoEncontradoEx {
        if (cadastroLivros.containsKey(codigoLivro)) {
            return cadastroLivros.get(codigoLivro);
        } else {
            throw new LivroNaoEncontradoEx("Livro nao encontrado: " + codigoLivro);
        }
    }

    public Hashtable<Integer, Usuario> getCadastroUsuarios() {
        return cadastroUsuarios;
    }

    public Hashtable<String, Livro> getCadastroLivros() {
        return cadastroLivros;
    }

    public Usuario getUsuario(Integer codigoUsuario) throws UsuarioNaoEncontradoEx {
        if (cadastroUsuarios.containsKey(codigoUsuario)) {
            return cadastroUsuarios.get(codigoUsuario);
        } else {
            throw new UsuarioNaoEncontradoEx("Usuario nao encontrado: " + codigoUsuario);
        }
    }

     
    public void salvaArquivo(Hashtable hashtable,String arquivo)
            throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(arquivo));
        oos.writeObject(hashtable);
        oos.close();
    }

   
    public void leArquivoUsuarios(String arquivo,String tipoArquivo) throws IOException, ClassNotFoundException,TipoDeArquivoInvalidoEx {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(arquivo));
        Hashtable hashtable = (Hashtable) ois.readObject();
        ois.close();

        if (tipoArquivo.equals("usuarios")) {
            cadastroUsuarios = (Hashtable<Integer, Usuario>) hashtable;
        } else if (tipoArquivo.equals("livros")) {
            cadastroLivros = (Hashtable<String, Livro>) hashtable;
        }
        else {
            throw new TipoDeArquivoInvalidoEx("Tipo de arquivo invalido: " + tipoArquivo);
        }

    }
    

    public void emprestaLivro(String livro, int usuario)
            throws LivroNaoEncontradoEx, UsuarioNaoEncontradoEx, CopiaNaoDisponivelEx {
        Livro livroValidado = getLivro(livro);
        Usuario usuarioValidado = getUsuario(usuario);

        livroValidado.empresta();
        usuarioValidado.addLivroHist(new GregorianCalendar(), livroValidado.getCodigoLivro());
        livroValidado.addUsuarioHist(new GregorianCalendar(),usuarioValidado.getCodigoUsuario());
    }

    public void devolveLivro(String livro, int usuario)
            throws LivroNaoEncontradoEx, UsuarioNaoEncontradoEx, CopiaNaoDisponivelEx, NenhumaCopiaEmprestadaEx {
        Livro livroValidado = getLivro(livro);
        Usuario usuarioValidado = getUsuario(usuario);

        livroValidado.devolve();
        GregorianCalendar dataAtual = new GregorianCalendar();

        Emprest emprestUsuario = usuarioValidado.getEmprestLivro(livroValidado);
        emprestUsuario.setDataDevolucao(dataAtual);

        EmprestPara emprestLivro = livroValidado.getEmprestParaByUsuario(usuarioValidado);

        if (emprestUsuario.getDataDevolucao().after(emprestLivro.getDataDevolucaoPrevista())) {
            System.out.println("Livro entregue com atraso");
        }

    }

    public String imprimeLivros() {
        StringBuilder sb = new StringBuilder();
        List<Livro> livros = new ArrayList<>(cadastroLivros.values());
        livros.sort(Comparator.comparing(Livro::getTitulo));

        for (Livro livro : livros) {
            sb.append(livro.toString()).append("\n");
        }
        return sb.toString();
    }

    public String imprimeUsuarios() {
        StringBuilder sb = new StringBuilder();
        List<Usuario> usuarios = new ArrayList<>(cadastroUsuarios.values());
        usuarios.sort(Comparator.comparing(Usuario::getNome));

        for (Usuario usuario : usuarios) {
            sb.append(usuario.toString()).append("\n");
        }
        return sb.toString();
    }

 
}