package lp2g25;

import lp2g25.biblioteca.*;
import lp2g25.biblioteca.exception.*;

import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class P3n25 {

    private Scanner scanner;
    private Biblioteca biblioteca;

    public P3n25() {
        biblioteca = new Biblioteca();
        scanner = new Scanner(System.in);
    }

    private void menuPrincipal() {
        while (true) {

            System.out.println("Bem vindo ao sistema de biblioteca");
            System.out.println("1 - Manutenção (Salvar e Carregar Arquivos)");
            System.out.println("2 - Cadastro");
            System.out.println("3 - Emprestimo");
            System.out.println("4 - Relatorio");
            System.out.println("5 - Sair");
            if (biblioteca.getCadastroUsuarios().size() == 0 || biblioteca.getCadastroLivros().size() == 0) {
                System.out.println("Sua biblioteca está vazia.");
                
            }

            try {
                int opcao = scanner.nextInt();

                switch (opcao) {
                    case 1:
                        menuManutencao();
                        break;

                    case 2:
                        menuCadastro();
                        break;

                    case 3:
                        menuEmprestimo();
                        break;    

                    case 4:
                        menuRelatorio();
                        break;

                    case 5:
                        System.out.println("Saindo...");
                        return;

                    default:
                        System.out.println("Opção inválida");
                        break;
                }

            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scanner.next();
            }

        }
    }

    private void menuManutencao() {
        while (true) {

            System.out.println("Manutenção");
            System.out.println("1 - Iniciar nova biblioteca");
            System.out.println("2 - Carregar biblioteca");
            System.out.println("3 - Salvar biblioteca");
            System.out.println("4 - Voltar");

            try {
                int opcao = scanner.nextInt();

                switch (opcao) {
                    case 1:
                        biblioteca = new Biblioteca();
                        break;

                    case 2:
                        System.out.println("Digite o nome do arquivo de usuários para carregar");
                        String arquivoUsuarios = scanner.next();
                        System.out.println("Digite o nome do arquivo de livros para carregar");
                        String arquivoLivros = scanner.next();
                        try {
                            biblioteca = new Biblioteca(arquivoUsuarios, arquivoLivros);
                            System.out.println("Biblioteca carregada com sucesso.");
                            return;
                        } catch (Exception e) {
                            System.out.println("Erro ao carregar biblioteca");
                        }
                        break;

                    case 3:
                        System.out.println("Digite o nome do arquivo de usuários para salvar");
                        arquivoUsuarios = scanner.next();
                        System.out.println("Digite o nome do arquivo de livros para salvar");
                        arquivoLivros = scanner.next();
                        try {
                            biblioteca.salvaArquivo(biblioteca.getCadastroUsuarios(), arquivoUsuarios);
                            biblioteca.salvaArquivo(biblioteca.getCadastroLivros(), arquivoLivros);
                            System.out.println("Biblioteca salva com sucesso.");
                        } catch (IOException e) {
                            System.out.println(e);
                        } catch (Exception e) {
                            System.out.println("Erro ao salvar biblioteca");
                        }
                        break;

                    case 4:
                        return;

                    default:
                        System.out.println("Opção inválida");
                        break;
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scanner.next();
            }
        }
    }

    private void menuCadastro() {
        while (true) {
            System.out.println("Menu de Cadastro");
            System.out.println("1 - Cadastrar usuário");
            System.out.println("2 - Cadastrar livro");
            System.out.println("3 - Salvar usuarios");
            System.out.println("4 - Salvar livros");
            System.out.println("5 - Voltar");

            try {
                int opcao = scanner.nextInt();

                switch (opcao) {
                    case 1:
                        System.out.println("Digite o primeiro nome:");
                        String nome = scanner.next();
                        
                          System.out.println("Digite o sobrenome:");
                          String sobreNome = scanner.next();
                          System.out.println("Digite o dia de nascimento:");
                          int dia = scanner.nextInt();
                          System.out.println("Digite o mês de nascimento:");
                          int mes = scanner.nextInt();
                          System.out.println("Digite o ano de nascimento:");
                          int ano = scanner.nextInt();
                          scanner.nextLine();
                          System.out.println("Digite o endereço:");
                          String endereco = scanner.nextLine();
                         
                         

                        Usuario novoUsuario = new Usuario(nome, sobreNome, dia, mes, ano, endereco);
                        biblioteca.addUsuario(novoUsuario);
                        System.out.println("Usuário cadastrado com sucesso.");
                        break;

                    case 2:
                        try {
                            scanner.nextLine();
                            System.out.println("Digite o código do livro:");
                            String codigoLivro = scanner.nextLine();
                            System.out.println("Digite o título do livro:");
                            String titulo = scanner.nextLine();
                            System.out.println("Digite a categoria do livro:");
                            String categoria = scanner.nextLine();
                            System.out.println("Digite a quantidade do livro:");
                            int quantidade = scanner.nextInt();

                            Livro novoLivro = new Livro(codigoLivro, titulo, categoria, quantidade);
                            biblioteca.addLivro(novoLivro);
                            System.out.println("Livro cadastrado com sucesso.");
                            break;
                        } catch (InputMismatchException e) {
                            System.out.println(
                                    "Entrada inválida. Por favor, digite um número inteiro para a quantidade.");
                            scanner.next();
                        }

                    case 3:
                        System.out.println("Digite o nome do arquivo de usuários para salvar:");
                        String arquivoUsuarios = scanner.next();
                        try {
                            biblioteca.salvaArquivo(biblioteca.getCadastroUsuarios(), arquivoUsuarios);
                            System.out.println("Usuários salvos com sucesso.");
                        } catch (IOException e) {
                            System.out.println(e);
                        } catch (Exception e) {
                            System.out.println("Erro ao salvar usuários.");
                        }
                        break;

                    case 4:
                        System.out.println("Digite o nome do arquivo de livros para salvar:");
                        String arquivoLivros = scanner.next();
                        try {
                            biblioteca.salvaArquivo(biblioteca.getCadastroLivros(), arquivoLivros);
                            System.out.println("Livros salvos com sucesso.");
                        } catch (IOException e) {
                            System.out.println(e);
                        } catch (Exception e) {
                            System.out.println("Erro ao salvar livros.");
                        }
                        break;

                    case 5:
                        return;

                    default:
                        System.out.println("Opção inválida");
                        break;
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scanner.next();
            }
        }
    }

    private void menuEmprestimo() {
        while (true) {
            System.out.println("Menu de Emprestimo");
            System.out.println("1 - Emprestar livro");
            System.out.println("2 - Devolver livro");
            System.out.println("3 - Listar Livros");
            System.out.println("4 - Voltar");

            try {
                int opcao = scanner.nextInt();

                switch (opcao) {
                    case 1:
                        System.out.println("Digite o código do livro:");
                        String codigoLivro = scanner.next();
                        System.out.println("Digite o código do usuário:");
                        int codigoUsuario = scanner.nextInt();
                        try {
                            biblioteca.emprestaLivro(codigoLivro, codigoUsuario);
                            System.out.println("Livro emprestado com sucesso.");
                            break;
                        } catch (LivroNaoEncontradoEx e) {
                            System.out.println(e);
                            
                        } catch (UsuarioNaoEncontradoEx e) {
                            System.out.println(e);
                            
                        } catch (CopiaNaoDisponivelEx e) {
                            System.out.println(e);
                            
                        } catch (Exception e) {
                            System.out.println("Erro ao emprestar livro.");
                        }
                        break;

                   case 2:
                        System.out.println("Digite o código do livro:");
                        codigoLivro = scanner.next();
                        System.out.println("Digite o código do usuário:");
                        codigoUsuario = scanner.nextInt();
                        try {
                            biblioteca.devolveLivro(codigoLivro, codigoUsuario);
                            System.out.println("Livro devolvido com sucesso.");
                            break;
                        } catch (LivroNaoEncontradoEx e) {
                            System.out.println(e);
                            
                        } catch (UsuarioNaoEncontradoEx e) {
                            System.out.println(e);
                            
                        } catch (NenhumaCopiaEmprestadaEx e) {
                            System.out.println(e);
                            
                        } catch (Exception e) {
                            System.out.println("Erro ao devolver livro.");
                        }
                        break;

                    case 3:
                        System.out.println(biblioteca.imprimeLivros());
                        break;

                    case 4:
                        return;

                    default:
                        System.out.println("Opção inválida");
                        break;     
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scanner.next();
            }
        }
                
                    
    }

    private void menuRelatorio() {
        while (true) {
            System.out.println("Menu de Relatório");
            System.out.println("1 - Relatório de cadastro de usuários");
            System.out.println("2 - Relatório de cadastro de livros");
            System.out.println("3 - Relatorio de um usuário");
            System.out.println("4 - Relatorio de um livro");
            System.out.println("5 - Voltar");

            try {
                int opcao = scanner.nextInt();

                switch (opcao) {
                    case 1:
                        System.out.println(biblioteca.imprimeUsuarios());
                        break;

                    case 2:
                        System.out.println(biblioteca.imprimeLivros());
                        break;

                    case 3:
                        System.out.println("Digite o código do usuário:");
                        int codigoUsuario = scanner.nextInt();
                        try {
                            Usuario usuario = biblioteca.getUsuario(codigoUsuario);
                            System.out.println(usuario.toString());
                        } catch (Exception e) {
                            System.out.println("Erro ao buscar usuário");
                        }
                        break;

                    case 4:
                        System.out.println("Digite o código do livro:");
                        String codigoLivro = scanner.next();
                        try {
                            Livro livro = biblioteca.getLivro(codigoLivro);
                            System.out.println(livro.toString());

                        } catch (Exception e) {
                            System.out.println("Erro ao buscar livro");
                        }
                        break;

                    case 5:
                        return;    

                    default:
                        System.out.println("Opção inválida");
                        break;
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada inválida. Por favor, digite um número inteiro.");
                scanner.next();
            }
        }
    }

    public static void main(String[] args) {

        P3n25 p3n25 = new P3n25();
        p3n25.menuPrincipal();
    }

}
