<h2 id="problem-to-solve">Problem to Solve</h2>

<p>In the game of <a href="https://scrabble.hasbro.com/en-us/rules">Scrabble</a>, players create words to score points, and the number of points is the sum of the point values of each letter in the word.</p>

<table>
  <thead>
    <tr>
      <th>A</th>
      <th>B</th>
      <th>C</th>
      <th>D</th>
      <th>E</th>
      <th>F</th>
      <th>G</th>
      <th>H</th>
      <th>I</th>
      <th>J</th>
      <th>K</th>
      <th>L</th>
      <th>M</th>
      <th>N</th>
      <th>O</th>
      <th>P</th>
      <th>Q</th>
      <th>R</th>
      <th>S</th>
      <th>T</th>
      <th>U</th>
      <th>V</th>
      <th>W</th>
      <th>X</th>
      <th>Y</th>
      <th>Z</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>3</td>
      <td>3</td>
      <td>2</td>
      <td>1</td>
      <td>4</td>
      <td>2</td>
      <td>4</td>
      <td>1</td>
      <td>8</td>
      <td>5</td>
      <td>1</td>
      <td>3</td>
      <td>1</td>
      <td>1</td>
      <td>3</td>
      <td>10</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>4</td>
      <td>4</td>
      <td>8</td>
      <td>4</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

<p>For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.</p>

<p>In a file called <code class="language-plaintext highlighter-rouge">scrabble.c</code> in a folder called <code class="language-plaintext highlighter-rouge">scrabble</code>, implement a program in C that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).</p>

<h2 id="demo">Demo</h2>

<script async="" data-autoplay="1" data-cols="80" data-loop="1" data-rows="12" id="asciicast-74B4kq3ftleKe6AdN0NxFV8CN" src="https://asciinema.org/a/74B4kq3ftleKe6AdN0NxFV8CN.js"></script>

<h2 id="advice">Advice</h2>

<p>Click the below toggles to read some advice!</p>

<details><summary>Write some code that you know will compile</summary><div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
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
  <li>Prompt for the user for two words</li>
  <li>Compute the score of each word</li>
  <li>Print the winner</li>
</ol>

<p>Let’s write some pseudcode as comments to remind you to do just that:</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>

    <span class="c1">// Compute the score of each word</span>

    <span class="c1">// Print the winner</span>
<span class="p">}</span>
</code></pre></div></div></details>

<div class="alert" data-alert="warning" role="alert"><p>Some problems in problem sets, like this one, might contain spoilers (like the next one) that ultimately walk you through the entire solution. While you are permitted to use this code, we really do strongly encourage you to try things out yourself first! The other problems in the problem set won’t have this sort of walkthrough, and typically the problem that contains the “full spoiler” is a warm-up version of the bigger problem you’ll later need to tackle.</p></div>

<details><summary>Convert the pseudocode to code</summary><p>First, consider how you might prompt the user for two words. Recall that <code class="language-plaintext highlighter-rouge">get_string</code>, a function in the CS50 library, can prompt the user for a string.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>
    <span class="n">string</span> <span class="n">word1</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 1: "</span><span class="p">);</span>
    <span class="n">string</span> <span class="n">word2</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 2: "</span><span class="p">);</span>

    <span class="c1">// Compute the score of each word</span>

    <span class="c1">// Print the winner</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Next consider how to compute the score of each word. Since the same scoring algorithm applies to both words, you have a good opportunity for <em>abstraction</em>. Here we’ll define a function called <code class="language-plaintext highlighter-rouge">compute_score</code> that takes a string, called <code class="language-plaintext highlighter-rouge">word</code>, as input, and then returns <code class="language-plaintext highlighter-rouge">word</code>’s score as an <code class="language-plaintext highlighter-rouge">int</code>.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>
    <span class="n">string</span> <span class="n">word1</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 1: "</span><span class="p">);</span>
    <span class="n">string</span> <span class="n">word2</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 2: "</span><span class="p">);</span>

    <span class="c1">// Compute the score of each word</span>
    <span class="kt">int</span> <span class="n">score1</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word1</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">score2</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word2</span><span class="p">);</span>

    <span class="c1">// Print the winner   </span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Compute and return score for word</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Now turn to implementing <code class="language-plaintext highlighter-rouge">compute_score</code>. To compute the score of a word, you need to know the point value of each letter in the word. You can associate letters and their point values with an <em>array</em>. Imagine an array of 26 <code class="language-plaintext highlighter-rouge">int</code>s, called <code class="language-plaintext highlighter-rouge">POINTS</code>, in which the first number is the point value for ‘A’, the second number is the point value for ‘B’, and so on. By declaring and initializing such an array outside of any single function, you can ensure this array is accessible to any function, including <code class="language-plaintext highlighter-rouge">compute_score</code>.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="c1">// Points assigned to each letter of the alphabet</span>
<span class="kt">int</span> <span class="n">POINTS</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">10</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">10</span><span class="p">};</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>
    <span class="n">string</span> <span class="n">word1</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 1: "</span><span class="p">);</span>
    <span class="n">string</span> <span class="n">word2</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 2: "</span><span class="p">);</span>

    <span class="c1">// Compute the score of each word</span>
    <span class="kt">int</span> <span class="n">score1</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word1</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">score2</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word2</span><span class="p">);</span>

    <span class="c1">// Print the winner   </span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Compute and return score for word</span>
<span class="p">}</span>
</code></pre></div></div>

<p>To implement <code class="language-plaintext highlighter-rouge">compute_score</code>, first try to find the point value of a single letter in <code class="language-plaintext highlighter-rouge">word</code>.</p>

<ul>
  <li data-marker="*">Recall that to find the character at the nth index of a string, <code class="language-plaintext highlighter-rouge">s</code>, you can write <code class="language-plaintext highlighter-rouge">s[n]</code>. So <code class="language-plaintext highlighter-rouge">word[0]</code>, for example, will give you the first character of <code class="language-plaintext highlighter-rouge">word</code>.</li>
  <li data-marker="*">Now, recall that computers represent characters using <a href="http://asciitable.com/">ASCII</a>, a standard that represents each character as a number.</li>
  <li data-marker="*">Recall too that the 0th index of <code class="language-plaintext highlighter-rouge">POINTS</code>, <code class="language-plaintext highlighter-rouge">POINTS[0]</code>, gives you the point value of ‘A’. Think about how you could transform the numeric representation of ‘A’ into the index of its point value. Now, what about ‘a’? You’ll need to apply different transformations to upper- and lower-case letters, so you may find the functions <a href="https://manual.cs50.io/3/isupper"><code class="language-plaintext highlighter-rouge">isupper</code></a> and <a href="https://manual.cs50.io/3/islower"><code class="language-plaintext highlighter-rouge">islower</code></a> to be helpful to you.</li>
  <li data-marker="*">Keep in mind that characters that are <em>not</em> letters should be given zero points For example, <code class="language-plaintext highlighter-rouge">!</code> is worth 0 points.</li>
</ul>

<p>If you can properly calculate the value of <em>one</em> character in <code class="language-plaintext highlighter-rouge">words</code>, odds are you can use a loop to sum the points for the rest of the characters. Once you’ve tried the above on your own, consider this (quite revealing!) hint below.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="c1">// Points assigned to each letter of the alphabet</span>
<span class="kt">int</span> <span class="n">POINTS</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">10</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">10</span><span class="p">};</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>
    <span class="n">string</span> <span class="n">word1</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 1: "</span><span class="p">);</span>
    <span class="n">string</span> <span class="n">word2</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 2: "</span><span class="p">);</span>

    <span class="c1">// Compute the score of each word</span>
    <span class="kt">int</span> <span class="n">score1</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word1</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">score2</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word2</span><span class="p">);</span>

    <span class="c1">// Print the winner   </span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Keep track of score</span>
    <span class="kt">int</span> <span class="n">score</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>

    <span class="c1">// Compute score for each character</span>
    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">len</span> <span class="o">=</span> <span class="n">strlen</span><span class="p">(</span><span class="n">word</span><span class="p">);</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
    <span class="p">{</span>
        <span class="k">if</span> <span class="p">(</span><span class="n">isupper</span><span class="p">(</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]))</span>
        <span class="p">{</span>
            <span class="n">score</span> <span class="o">+=</span> <span class="n">POINTS</span><span class="p">[</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">-</span> <span class="sc">'A'</span><span class="p">];</span>
        <span class="p">}</span>
        <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">islower</span><span class="p">(</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]))</span>
        <span class="p">{</span>
            <span class="n">score</span> <span class="o">+=</span> <span class="n">POINTS</span><span class="p">[</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">-</span> <span class="sc">'a'</span><span class="p">];</span>
        <span class="p">}</span>
    <span class="p">}</span>

    <span class="k">return</span> <span class="n">score</span><span class="p">;</span>
<span class="p">}</span>
</code></pre></div></div>

<p>Finally, finish your pseudocode’s last step: printing the winner. Recall that an <code class="language-plaintext highlighter-rouge">if</code> statement can be used to check if a condition is true, and that the additional usage of <code class="language-plaintext highlighter-rouge">else if</code> or <code class="language-plaintext highlighter-rouge">else</code> can check for other (exclusive) conditions.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="k">if</span> <span class="p">(</span><span class="cm">/* Player 1 wins */</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// ...</span>
<span class="p">}</span>
<span class="k">else</span> <span class="nf">if</span> <span class="p">(</span><span class="cm">/* Player 2 wins */</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// ...</span>
<span class="p">}</span>
<span class="k">else</span>
<span class="p">{</span>
    <span class="c1">// ...</span>
<span class="p">}</span>
</code></pre></div></div>

<p>And once you’ve tried the above, feel free to take a peek at the hint (or, rather, complete solution!) below.</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;ctype.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;cs50.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;stdio.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;string.h&gt;</span><span class="cp">
</span>
<span class="c1">// Points assigned to each letter of the alphabet</span>
<span class="kt">int</span> <span class="n">POINTS</span><span class="p">[]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">5</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="mi">10</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="mi">4</span><span class="p">,</span> <span class="mi">10</span><span class="p">};</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">);</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Prompt the user for two words</span>
    <span class="n">string</span> <span class="n">word1</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 1: "</span><span class="p">);</span>
    <span class="n">string</span> <span class="n">word2</span> <span class="o">=</span> <span class="n">get_string</span><span class="p">(</span><span class="s">"Player 2: "</span><span class="p">);</span>

    <span class="c1">// Compute the score of each word</span>
    <span class="kt">int</span> <span class="n">score1</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word1</span><span class="p">);</span>
    <span class="kt">int</span> <span class="n">score2</span> <span class="o">=</span> <span class="n">compute_score</span><span class="p">(</span><span class="n">word2</span><span class="p">);</span>

    <span class="c1">// Print the winner   </span>
    <span class="k">if</span> <span class="p">(</span><span class="n">score1</span> <span class="o">&gt;</span> <span class="n">score2</span><span class="p">)</span>
    <span class="p">{</span>
        <span class="n">printf</span><span class="p">(</span><span class="s">"Player 1 wins!</span><span class="se">\n</span><span class="s">"</span><span class="p">);</span>
    <span class="p">}</span>
    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">score1</span> <span class="o">&lt;</span> <span class="n">score2</span><span class="p">)</span>
    <span class="p">{</span>
        <span class="n">printf</span><span class="p">(</span><span class="s">"Player 2 wins!</span><span class="se">\n</span><span class="s">"</span><span class="p">);</span>
    <span class="p">}</span>
    <span class="k">else</span>
    <span class="p">{</span>
        <span class="n">printf</span><span class="p">(</span><span class="s">"Tie!</span><span class="se">\n</span><span class="s">"</span><span class="p">);</span>
    <span class="p">}</span>
<span class="p">}</span>

<span class="kt">int</span> <span class="nf">compute_score</span><span class="p">(</span><span class="n">string</span> <span class="n">word</span><span class="p">)</span>
<span class="p">{</span>
    <span class="c1">// Keep track of score</span>
    <span class="kt">int</span> <span class="n">score</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span>

    <span class="c1">// Compute score for each character</span>
    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">len</span> <span class="o">=</span> <span class="n">strlen</span><span class="p">(</span><span class="n">word</span><span class="p">);</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">len</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span>
    <span class="p">{</span>
        <span class="k">if</span> <span class="p">(</span><span class="n">isupper</span><span class="p">(</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]))</span>
        <span class="p">{</span>
            <span class="n">score</span> <span class="o">+=</span> <span class="n">POINTS</span><span class="p">[</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">-</span> <span class="sc">'A'</span><span class="p">];</span>
        <span class="p">}</span>
        <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">islower</span><span class="p">(</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]))</span>
        <span class="p">{</span>
            <span class="n">score</span> <span class="o">+=</span> <span class="n">POINTS</span><span class="p">[</span><span class="n">word</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">-</span> <span class="sc">'a'</span><span class="p">];</span>
        <span class="p">}</span>
    <span class="p">}</span>

    <span class="k">return</span> <span class="n">score</span><span class="p">;</span>
<span class="p">}</span>
</code></pre></div></div></details>

<h2 id="how-to-test">How to Test</h2>

<p>Your program should behave per the examples below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./scrabble
Player 1: Scrabble
Player 2: wiNNeR
Player 1 wins!
</code></pre></div></div>

<h3 id="correctness">Correctness</h3>

<p>In your terminal, execute the below to check your work’s correctness.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>check50 cs50/problems/2024/x/scrabble
</code></pre></div></div>

<h3 id="style">Style</h3>

<p>Execute the below to evaluate the style of your code using <code class="language-plaintext highlighter-rouge">style50</code>.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>style50 scrabble.c
</code></pre></div></div>

<h2 id="how-to-submit">How to Submit</h2>

<p>In your terminal, execute the below to submit your work.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>submit50 cs50/problems/2024/x/scrabble
</code></pre></div></div> 
</body></html>