<h2 id="problem-to-solve">Problem to Solve</h2>

<p>Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP instead. Upon receiving such messages from Caesar, recipients would have to “decrypt” them by shifting letters in the opposite direction by the same number of places.</p>

<p>The secrecy of this “cryptosystem” relied on only Caesar and the recipients knowing a secret, the number of places by which Caesar had shifted his letters (e.g., 1). Not particularly secure by modern standards, but, hey, if you’re perhaps the first in the world to do it, pretty secure!</p>

<p>Unencrypted text is generally called <em>plaintext</em>. Encrypted text is generally called <em>ciphertext</em>. And the secret used is called a <em>key</em>.</p>

<p>To be clear, then, here’s how encrypting <code class="language-plaintext highlighter-rouge">HELLO</code> with a key of \(1\) yields <code class="language-plaintext highlighter-rouge">IFMMP</code>:</p>

<table>
  <thead>
    <tr>
      <th>plaintext</th>
      <th><code class="language-plaintext highlighter-rouge">H</code></th>
      <th><code class="language-plaintext highlighter-rouge">E</code></th>
      <th><code class="language-plaintext highlighter-rouge">L</code></th>
      <th><code class="language-plaintext highlighter-rouge">L</code></th>
      <th><code class="language-plaintext highlighter-rouge">O</code></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>+ key</td>
      <td>\(1\)</td>
      <td>\(1\)</td>
      <td>\(1\)</td>
      <td>\(1\)</td>
      <td>\(1\)</td>
    </tr>
    <tr>
      <td>= ciphertext</td>
      <td><code class="language-plaintext highlighter-rouge">I</code></td>
      <td><code class="language-plaintext highlighter-rouge">F</code></td>
      <td><code class="language-plaintext highlighter-rouge">M</code></td>
      <td><code class="language-plaintext highlighter-rouge">M</code></td>
      <td><code class="language-plaintext highlighter-rouge">P</code></td>
    </tr>
  </tbody>
</table>

<p>More formally, Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by \(k\) positions. More formally, if \(p\) is some plaintext (i.e., an unencrypted message), \(p_i\) is the \(i^{th}\) character in \(p\), and \(k\) is a secret key (i.e., a non-negative integer), then each letter, \(c_i\), in the ciphertext, \(c\), is computed as</p>

\[c_i = (p_i + k)\space\%\space26\]

<p>wherein \(\%\space26\) here means “remainder when dividing by 26.” This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely. Indeed, for the sake of discussion, think of A (or a) as \(0\), B (or b) as \(1\), …, H (or h) as \(7\), I (or i) as \(8\), …, and Z (or z) as \(25\). Suppose that Caesar just wants to say <code class="language-plaintext highlighter-rouge">Hi</code> to someone confidentially using, this time, a key, \(k\), of 3. And so his plaintext, \(p\), is <code class="language-plaintext highlighter-rouge">Hi</code>, in which case his plaintext’s first character, \(p_0\), is <code class="language-plaintext highlighter-rouge">H</code> (aka 7), and his plaintext’s second character, \(p_1\), is <code class="language-plaintext highlighter-rouge">i</code> (aka 8). His ciphertext’s first character, \(c_0\), is thus <code class="language-plaintext highlighter-rouge">K</code>, and his ciphertext’s second character, \(c_1\), is thus <code class="language-plaintext highlighter-rouge">L</code>. Make sense?</p>

<p>In a file called <code class="language-plaintext highlighter-rouge">caesar.c</code> in a folder called <code class="language-plaintext highlighter-rouge">caesar</code>, write a program that enables you to encrypt messages using Caesar’s cipher. At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.</p>

<h2 id="specification">Specification</h2>

<p>Design and implement a program, <code class="language-plaintext highlighter-rouge">caesar</code>, that encrypts messages using Caesar’s cipher.</p>

<ul>
  <li data-marker="*">Implement your program in a file called <code class="language-plaintext highlighter-rouge">caesar.c</code> in a directory called <code class="language-plaintext highlighter-rouge">caesar</code>.</li>
  <li data-marker="*">Your program must accept a single command-line argument, a non-negative integer. Let’s call it \(k\) for the sake of discussion.</li>
  <li data-marker="*">If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with <code class="language-plaintext highlighter-rouge">printf</code>) and return from <code class="language-plaintext highlighter-rouge">main</code> a value of <code class="language-plaintext highlighter-rouge">1</code> (which tends to signify an error) immediately.</li>
  <li data-marker="*">If any of the characters of the command-line argument is not a decimal digit, your program should print the message <code class="language-plaintext highlighter-rouge">Usage: ./caesar key</code> and return from <code class="language-plaintext highlighter-rouge">main</code> a value of <code class="language-plaintext highlighter-rouge">1</code>.</li>
  <li data-marker="*">Do not assume that \(k\) will be less than or equal to 26. Your program should work for all non-negative integral values of \(k\) less than \(2^{31} - 26\). In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for \(k\) that’s too big or almost too big to fit in an <code class="language-plaintext highlighter-rouge">int</code>. (Recall that an <code class="language-plaintext highlighter-rouge">int</code> can overflow.) But, even if \(k\) is greater than \(26\), alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if \(k\) is \(27\), <code class="language-plaintext highlighter-rouge">A</code> should not become <code class="language-plaintext highlighter-rouge">\</code> even though <code class="language-plaintext highlighter-rouge">\</code> is \(27\) positions away from <code class="language-plaintext highlighter-rouge">A</code> in ASCII, per <a href="https://www.asciitable.com/">asciitable.com</a>; <code class="language-plaintext highlighter-rouge">A</code> should become <code class="language-plaintext highlighter-rouge">B</code>, since <code class="language-plaintext highlighter-rouge">B</code> is \(27\) positions away from <code class="language-plaintext highlighter-rouge">A</code>, provided you wrap around from <code class="language-plaintext highlighter-rouge">Z</code> to <code class="language-plaintext highlighter-rouge">A</code>.</li>
  <li data-marker="*">Your program must output <code class="language-plaintext highlighter-rouge">plaintext:  </code> (with two spaces but without a newline) and then prompt the user for a <code class="language-plaintext highlighter-rouge">string</code> of plaintext (using <code class="language-plaintext highlighter-rouge">get_string</code>).</li>
  <li data-marker="*">Your program must output <code class="language-plaintext highlighter-rouge">ciphertext: </code> (with one space but without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by <em>k</em> positions; non-alphabetical characters should be outputted unchanged.</li>
  <li data-marker="*">Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.</li>
  <li data-marker="*">After outputting ciphertext, you should print a newline. Your program should then exit by returning <code class="language-plaintext highlighter-rouge">0</code> from <code class="language-plaintext highlighter-rouge">main</code>.</li>
</ul>

<h2 id="advice">Advice</h2>

<p>How to begin? Let’s approach this problem one step at a time.</p>

<h3 id="pseudocode">Pseudocode</h3>

<p>First write, try to write a <code class="language-plaintext highlighter-rouge">main</code> function in <code class="language-plaintext highlighter-rouge">caesar.c</code> that implements the program using just pseudocode, even if not (yet!) sure how to write it in actual code.</p>

<details><summary>Hint</summary><p>There’s more than one way to do this, so here’s just one!</p>

<div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">int</span> <span class="n">argc</span><span class="p">,</span> <span class="n">string</span> <span class="n">argv</span><span class="p">[])</span>
<span class="p">{</span>
    <span class="c1">// Make sure program was run with just one command-line argument</span>

    <span class="c1">// Make sure every character in argv[1] is a digit</span>

    <span class="c1">// Convert argv[1] from a `string` to an `int`</span>

    <span class="c1">// Prompt user for plaintext</span>

    <span class="c1">// For each character in the plaintext:</span>

        <span class="c1">// Rotate the character if it's a letter</span>
<span class="p">}</span>
</code></pre></div></div>

<p>It’s okay to edit your own pseudocode after seeing ours here, but don’t simply copy/paste ours into your own!</p></details>

<h3 id="counting-command-line-arguments">Counting Command-Line Arguments</h3>

<p>Whatever your pseudocode, let’s first write only the C code that checks whether the program was run with a single command-line argument before adding additional functionality.</p>

<p>Specifically, modify <code class="language-plaintext highlighter-rouge">main</code> in <code class="language-plaintext highlighter-rouge">caesar.c</code> in such a way that, if the user provides no command-line arguments, or two or more, the function prints <code class="language-plaintext highlighter-rouge">"Usage: ./caesar key\n"</code> and then returns <code class="language-plaintext highlighter-rouge">1</code>, effectively exiting the program. If the user provides exactly one command-line argument, the program should print nothing and simply return <code class="language-plaintext highlighter-rouge">0</code>. The program should thus behave per the below.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./caesar
Usage: ./caesar key
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./caesar 1 2 3
Usage: ./caesar key
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./caesar 1
</code></pre></div></div>

<details><summary>Hints</summary><ul>
  <li data-marker="*">Recall that you can print with <code class="language-plaintext highlighter-rouge">printf</code>.</li>
  <li data-marker="*">Recall that a function can return a value with <code class="language-plaintext highlighter-rouge">return</code>.</li>
  <li data-marker="*">Recall that <code class="language-plaintext highlighter-rouge">argc</code> contains the number of command-line arguments passed to a program, plus the program’s own name.</li>
</ul></details>

<h3 id="checking-the-key">Checking the Key</h3>

<p>Now that your program is (hopefully!) accepting input as prescribed, it’s time for another step.</p>

<p>Add to <code class="language-plaintext highlighter-rouge">caesar.c</code>, below <code class="language-plaintext highlighter-rouge">main</code>, a function called, e.g., <code class="language-plaintext highlighter-rouge">only_digits</code> that takes a <code class="language-plaintext highlighter-rouge">string</code> as an argument and returns <code class="language-plaintext highlighter-rouge">true</code> if that <code class="language-plaintext highlighter-rouge">string</code> contains only digits, <code class="language-plaintext highlighter-rouge">0</code> through <code class="language-plaintext highlighter-rouge">9</code>, else it returns <code class="language-plaintext highlighter-rouge">false</code>. Be sure to add the function’s prototype above <code class="language-plaintext highlighter-rouge">main</code> as well.</p>

<details><summary>Hints</summary><ul>
  <li data-marker="*">Odds are you’ll want a prototype like:
    <div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="n">bool</span> <span class="nf">only_digits</span><span class="p">(</span><span class="n">string</span> <span class="n">s</span><span class="p">);</span>
</code></pre></div>    </div>
    <p>And be sure to include <code class="language-plaintext highlighter-rouge">cs50.h</code> atop your file, so that the compiler recognizes <code class="language-plaintext highlighter-rouge">string</code> (and <code class="language-plaintext highlighter-rouge">bool</code>).</p>
  </li>
  <li data-marker="*">Recall that a <code class="language-plaintext highlighter-rouge">string</code> is just an array of <code class="language-plaintext highlighter-rouge">char</code>s.</li>
  <li data-marker="*">Recall that <code class="language-plaintext highlighter-rouge">strlen</code>, declared in <code class="language-plaintext highlighter-rouge">string.h</code>, calculates the length of a <code class="language-plaintext highlighter-rouge">string</code>.</li>
  <li data-marker="*">You might find <code class="language-plaintext highlighter-rouge">isdigit</code>, declared in <code class="language-plaintext highlighter-rouge">ctype.h</code>, to be helpful, per <a href="https://manual.cs50.io/">manual.cs50.io</a>. But note that it only checks one <code class="language-plaintext highlighter-rouge">char</code> at a time!</li>
</ul></details>

<p>Then modify <code class="language-plaintext highlighter-rouge">main</code> in such a way that it calls <code class="language-plaintext highlighter-rouge">only_digits</code> on <code class="language-plaintext highlighter-rouge">argv[1]</code>. If that function returns <code class="language-plaintext highlighter-rouge">false</code>, then <code class="language-plaintext highlighter-rouge">main</code> should print <code class="language-plaintext highlighter-rouge">"Usage: ./caesar key\n"</code> and return <code class="language-plaintext highlighter-rouge">1</code>. Else <code class="language-plaintext highlighter-rouge">main</code> should simply return <code class="language-plaintext highlighter-rouge">0</code>. The program should thus behave per the below:</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./caesar 42
</code></pre></div></div>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./caesar banana
Usage: ./caesar key
</code></pre></div></div>

<h3 id="using-the-key">Using the Key</h3>

<p>Now modify <code class="language-plaintext highlighter-rouge">main</code> in such a way that it converts <code class="language-plaintext highlighter-rouge">argv[1]</code> to an <code class="language-plaintext highlighter-rouge">int</code>. You might find <code class="language-plaintext highlighter-rouge">atoi</code>, declared in <code class="language-plaintext highlighter-rouge">stdlib.h</code>, to be helpful, per <a href="https://manual.cs50.io/">manual.cs50.io</a>. And then use <code class="language-plaintext highlighter-rouge">get_string</code> to prompt the user for some plaintext with <code class="language-plaintext highlighter-rouge">"plaintext:  "</code>.</p>

<p>Then, implement a function called, e.g., <code class="language-plaintext highlighter-rouge">rotate</code>, that takes a <code class="language-plaintext highlighter-rouge">char</code> as input and also an <code class="language-plaintext highlighter-rouge">int</code>, and rotates that <code class="language-plaintext highlighter-rouge">char</code> by that many positions if it’s a letter (i.e., alphabetical), wrapping around from <code class="language-plaintext highlighter-rouge">Z</code> to <code class="language-plaintext highlighter-rouge">A</code> (and from <code class="language-plaintext highlighter-rouge">z</code> to <code class="language-plaintext highlighter-rouge">a</code>) as needed. If the <code class="language-plaintext highlighter-rouge">char</code> is not a letter, the function should instead return the same <code class="language-plaintext highlighter-rouge">char</code> unchanged.</p>

<details><summary>Hints</summary><ul>
  <li data-marker="*">Odds are you’ll want a prototype like:
    <div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="kt">char</span> <span class="nf">rotate</span><span class="p">(</span><span class="kt">char</span> <span class="n">c</span><span class="p">,</span> <span class="kt">int</span> <span class="n">n</span><span class="p">);</span>
</code></pre></div>    </div>
    <p>A function call like</p>
    <div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="n">rotate</span><span class="p">(</span><span class="sc">'A'</span><span class="p">,</span> <span class="mi">1</span><span class="p">)</span>
</code></pre></div>    </div>
    <p>or even</p>
    <div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>rotate('A', 27)
</code></pre></div>    </div>
    <p>should thus return <code class="language-plaintext highlighter-rouge">'B'</code>. And a function call like</p>
    <div class="language-c highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="n">rotate</span><span class="p">(</span><span class="sc">'!'</span><span class="p">,</span> <span class="mi">13</span><span class="p">)</span>
</code></pre></div>    </div>
    <p>should return <code class="language-plaintext highlighter-rouge">'!'</code>.</p>
  </li>
  <li data-marker="*">Recall that you can explicitly “cast” a <code class="language-plaintext highlighter-rouge">char</code> to an <code class="language-plaintext highlighter-rouge">int</code> with <code class="language-plaintext highlighter-rouge">(int)</code>, and an <code class="language-plaintext highlighter-rouge">int</code> to a <code class="language-plaintext highlighter-rouge">char</code> with <code class="language-plaintext highlighter-rouge">(char)</code>. Or you can do so implicitly by simply treating one as the other.</li>
  <li data-marker="*">Odds are you’ll want to subtract the ASCII value of <code class="language-plaintext highlighter-rouge">'A'</code> from any uppercase letters, so as to treat <code class="language-plaintext highlighter-rouge">'A'</code> as <code class="language-plaintext highlighter-rouge">0</code>, <code class="language-plaintext highlighter-rouge">'B'</code> as <code class="language-plaintext highlighter-rouge">1</code>, and so forth, while performing arithmetic. And then add it back when done with the same.</li>
  <li data-marker="*">Odds are you’ll want to subtract the ASCII value of <code class="language-plaintext highlighter-rouge">'a'</code> from any lowercase letters, so as to treat <code class="language-plaintext highlighter-rouge">'a'</code> as <code class="language-plaintext highlighter-rouge">0</code>, <code class="language-plaintext highlighter-rouge">'b'</code> as <code class="language-plaintext highlighter-rouge">1</code>, and so forth, while performing arithmetic. And then add it back when done with the same.</li>
  <li data-marker="*">You might find some other functions declared in <code class="language-plaintext highlighter-rouge">ctype.h</code> to be helpful, per <a href="https://manual.cs50.io/">manual.cs50.io</a>.</li>
  <li data-marker="*">Odds are you’ll find <code class="language-plaintext highlighter-rouge">%</code> helpful when “wrapping around” arithmetically from a value like <code class="language-plaintext highlighter-rouge">25</code> to <code class="language-plaintext highlighter-rouge">0</code>.</li>
</ul></details>

<p>Then modify <code class="language-plaintext highlighter-rouge">main</code> in such a way that it prints <code class="language-plaintext highlighter-rouge">"ciphertext: "</code> and then iterates over every <code class="language-plaintext highlighter-rouge">char</code> in the user’s plaintext, calling <code class="language-plaintext highlighter-rouge">rotate</code> on each, and printing the return value thereof.</p>

<details><summary>Hints</summary><ul>
  <li data-marker="*">Recall that <code class="language-plaintext highlighter-rouge">printf</code> can print a <code class="language-plaintext highlighter-rouge">char</code> using <code class="language-plaintext highlighter-rouge">%c</code>.</li>
  <li data-marker="*">If you’re not seeing any output at all when you call <code class="language-plaintext highlighter-rouge">printf</code>, odds are it’s because you’re printing characters outside of the valid ASCII range from 0 to 127. Try printing characters temporarily as numbers (using <code class="language-plaintext highlighter-rouge">%i</code> instead of <code class="language-plaintext highlighter-rouge">%c</code>) to see what values you’re printing!</li>
</ul></details>

<h2 id="how-to-test">How to Test</h2>

<h3 id="correctness">Correctness</h3>

<p>In your terminal, execute the below to check your work’s correctness.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>check50 cs50/problems/2024/x/caesar
</code></pre></div></div>

<details><summary>How to Use <code>debug50</code></summary><p>Looking to run <code class="language-plaintext highlighter-rouge">debug50</code>? You can do so as follows, after compiling your code successfully with <code class="language-plaintext highlighter-rouge">make</code>,</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>debug50 ./caesar KEY
</code></pre></div></div>

<p>wherein <code class="language-plaintext highlighter-rouge">KEY</code> is the key you give as a command-line argument to your program. Note that running</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>debug50 ./caesar
</code></pre></div></div>

<p>will (ideally!) cause your program end by prompting the user for a key.</p></details>

<h3 id="style">Style</h3>

<p>Execute the below to evaluate the style of your code using <code class="language-plaintext highlighter-rouge">style50</code>.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>style50 caesar.c
</code></pre></div></div>

<h2 id="how-to-submit">How to Submit</h2>

<p>In your terminal, execute the below to submit your work.</p>

<div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>submit50 cs50/problems/2024/x/caesar
</code></pre></div></div>
</body></html>