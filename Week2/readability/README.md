<h2 id="problem-to-solve">Problem to Solve</h2>

<p>According to <a href="https://www.scholastic.com/teachers/teaching-tools/collections/guided-reading-book-lists-for-every-level.html">Scholastic</a>, E.B. White’s <em>Charlotte’s Web</em> is between a second- and fourth-grade reading level, and Lois Lowry’s <em>The Giver</em> is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?</p>

<p>Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!</p>

<p>In a file called <code class="language-plaintext highlighter-rouge">readability.c</code> in a folder called <code class="language-plaintext highlighter-rouge">readability</code>, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.</p>

<h2 id="background">Background</h2>

<p>So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.</p>

<p>A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the <em>Coleman-Liau index</em>. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>index = 0.0588 * L - 0.296 * S - 15.8
</code></pre></div></div>

<p>where <code class="language-plaintext highlighter-rouge">L</code> is the average number of letters per 100 words in the text, and <code class="language-plaintext highlighter-rouge">S</code> is the average number of sentences per 100 words in the text.</p>

<h2 id="advice">Advice</h2>

<p>Click the below toggles to read some advice!</p>

<details><summary>Write some code that you know will compile</summary><div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>

<span class="p">}</span>
</code></pre></div></div>

<p>Notice that you’ve now included a few header files that will give you access to functions which might help you solve this problem.</p></details>

<details><summary>Write some pseudocode before writing more code</summary><p>If unsure how to solve the problem itself, break it down into smaller problems that you can probably solve first. For instance, this problem is really only a handful of problems:</p>

<ol>
  <li>Prompt the user for some text</li>
  <li>Count the number of letters, words, and sentences in the text</li>
  <li>Compute the Coleman-Liau index</li>
  <li>Print the grade level</li>
</ol>

<p>Let’s write some pseudcode as comments to remind you to do just that:</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for some text</span>

    <span class="c1">// Count the number of letters, words, and sentences in the text</span>

    <span class="c1">// Compute the Coleman-Liau index</span>

    <span class="c1">// Print the grade level</span>
<span class="p">}</span>
</code></pre></div></div></details>

<details><summary>Convert the pseudocode to code</summary><p>First, consider how you might prompt the user for some text. Recall that <code class="language-plaintext highlighter-rouge">get_string</code>, a function in the CS50 library, can prompt the user for a string.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for some text</span>
    <span class="n">string</span> <span class="n">text</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Text: "</span><span class="p">);</span>

    <span class="c1">// Count the number of letters, words, and sentences in the text</span>

    <span class="c1">// Compute the Coleman-Liau index</span>

    <span class="c1">// Print the grade level</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Now that you’ve collected input from the user, you can begin to analyze that input. First, try to count the number of letters in the text. Consider letters to be uppercase or lowercase alphabetical character, not punctuation, digits, or other symbols.</p>

<p>One way to approach this problem is to create a function called <code class="language-plaintext highlighter-rouge">count_letters</code> that takes a string, <code class="language-plaintext highlighter-rouge">text</code>, as input, and then returns the number of letters in that text as an <code class="language-plaintext highlighter-rouge">int</code>.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of letters in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>You’ll need to write your own code to count the number of letters in the text. But someone more experienced than you may have already written a function to determine if a character is alphabetical. This is a good opportunity to use the <a href="https://manual.cs50.io/">CS50 manual</a>, a collection of explanations of common functions in the C Standard Library.</p>

<p>You can integrate <code class="language-plaintext highlighter-rouge">count_letters</code> into the code you’ve already written, as follows.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for some text</span>
    <span class="n">string</span> <span class="n">text</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Text: "</span><span class="p">);</span>

    <span class="c1">// Count the number of letters, words, and sentences in the text</span>
    <span class="kt">int</span> <span class="n">letters</span> <span class="o">=</span> <span class="n">count_letters</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>

    <span class="c1">// Compute the Coleman-Liau index</span>

    <span class="c1">// Print the grade level</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of letters in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Next, write a function to count words.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">int</span> <span class="nf">count_words</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of words in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:</p>

<ul>
  <li data-marker="*">will contain at least one word;</li>
  <li data-marker="*">will not start or end with a space; and</li>
  <li data-marker="*">will not have multiple spaces in a row.</li>
</ul>

<p>Under those assumptions, you might be able to find a relationship between the number words and the number of spaces. You are, of course, welcome to attempt a solution that will tolerate multiple spaces between words or indeed, no words!</p>

<p>You can now integrate <code class="language-plaintext highlighter-rouge">count_words</code> into your program as follows:</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>
<span class="kt">int</span> <span class="nf">count_words</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for some text</span>
    <span class="n">string</span> <span class="n">text</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Text: "</span><span class="p">);</span>

    <span class="c1">// Count the number of letters, words, and sentences in the text</span>
    <span class="kt">int</span> <span class="n">letters</span> <span class="o">=</span> <span class="n">count_letters</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">words</span> <span class="o">=</span> <span class="n">count_words</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>

    <span class="c1">// Compute the Coleman-Liau index</span>

    <span class="c1">// Print the grade level</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of letters in text</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_words</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of words in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Finally, write a function to count sentences. You can consider any sequence of characters that ends with a <code class="language-plaintext highlighter-rouge">.</code> or a <code class="language-plaintext highlighter-rouge">!</code> or a <code class="language-plaintext highlighter-rouge">?</code> to be a sentence.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">int</span> <span class="nf">count_sentences</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of sentences in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>You can integrate <code class="language-plaintext highlighter-rouge">count_sentences</code> into your program as follows:</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;math.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>
<span class="kt">int</span> <span class="nf">count_words</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>
<span class="kt">int</span> <span class="nf">count_sentences</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for some text</span>
    <span class="n">string</span> <span class="n">text</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Text: "</span><span class="p">);</span>

    <span class="c1">// Count the number of letters, words, and sentences in the text</span>
    <span class="kt">int</span> <span class="n">letters</span> <span class="o">=</span> <span class="n">count_letters</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">words</span> <span class="o">=</span> <span class="n">count_words</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">sentences</span> <span class="o">=</span> <span class="n">count_sentences</span><span class="p">(</span><span class="n">text</span><span class="p">);</span>

    <span class="c1">// Compute the Coleman-Liau index</span>

    <span class="c1">// Print the grade level</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_letters</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of letters in text</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_words</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of words in text</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">count_sentences</span><span class="p">(</span><span class="n">string</span> <span class="n">text</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Return the number of sentences in text</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Finally, compute the Coleman-Liau index and print the resulting grade level.</p>

<ul>
  <li data-marker="*">Recall that the Coleman-Liau index is computed using <code class="language-plaintext highlighter-rouge">index = 0.0588 * L - 0.296 * S - 15.8</code></li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">L</code> is the average number of letters per 100 words in the text: that is, the number of letters divided by the number of words, all multiplied by 100.</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">S</code> is the average number of sentences per 100 words in the text: that is, the number of sentences divided by the number of words, all multiplied by 100.</li>
  <li data-marker="*">You’ll want to round the result to the nearest whole number, so recall that <code class="language-plaintext highlighter-rouge">round</code> is declared in <code class="language-plaintext highlighter-rouge">math.h</code>, per <a href="https://manual.cs50.io/">manual.cs50.io</a>.</li>
  <li data-marker="*">Recall that, when dividing values of type <code class="language-plaintext highlighter-rouge">int</code> in C, the result will also be an <code class="language-plaintext highlighter-rouge">int</code>, with any remainder (i.e., digits after the decimal point) discarded. Put another way, the result will be “truncated.” You might want to cast your one or more values to <code class="language-plaintext highlighter-rouge">float</code> before performing division when calculating <code class="language-plaintext highlighter-rouge">L</code> and <code class="language-plaintext highlighter-rouge">S</code>!</li>
</ul>

<p>If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of outputting an exact index number. If the index number is less than 1, your program should output “Before Grade 1”.</p></details>

<h2 id="how-to-test">How to Test</h2>

<p>Try running your program on the following texts, to ensure you see the specified grade level. Be sure to copy only the text, no extra spaces.</p>

<ul>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">One fish. Two fish. Red fish. Blue fish.</code> (Before Grade 1)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">Would you like them here or there? I would not like them here or there. I would not like them anywhere.</code> (Grade 2)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">Congratulations! Today is your day. You're off to Great Places! You're off and away!</code> (Grade 3)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.</code> (Grade 5)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.</code> (Grade 7)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"</code> (Grade 8)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.</code> (Grade 8)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.</code> (Grade 9)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.</code> (Grade 10)</li>
  <li data-marker="*"><code class="language-plaintext highlighter-rouge">A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.</code> (Grade 16+)</li>
</ul>

<h3 id="correctness">Correctness</h3>

<p>In your terminal, execute the below to check your work’s correctness.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>check50 cs50/problems/2024/x/readability
</code></pre></div></div>

<h3 id="style">Style</h3>

<p>Execute the below to evaluate the style of your code using <code class="language-plaintext highlighter-rouge">style50</code>.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>style50 readability.c
</code></pre></div></div>

<h2 id="how-to-submit">How to Submit</h2>

<p>In your terminal, execute the below to submit your work.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>submit50 cs50/problems/2024/x/readability
</code></pre></div></div>  

</body></html>