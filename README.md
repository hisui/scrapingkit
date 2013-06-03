# ScrapingKit

Webページのスクレイピングを行うObjective-C用のライブラリーです。

  - ill-formedなHTMLのパース＆DOM化
  - CSS(Selector Level 4)セレクターによるDOM要素の選択操作
    - jQueryのDOM選択のような、気軽な記述ができることを目標にしています
  - 簡単に使えるWebクライアントAPI（未実装）

Example
-------
```objective-c
#import <SFScrapingKit.h>

int main(int argc, char **argv)
{
    const NSString *HTML_DATA = ...;

    // URLを直接開く機能は未実装です。。
    // [SFNodeList open:@"https://github.com/hisui/scrapingkit/README.md"]
    [SFNodeList nodeListWithHTML:HTML_DATA]
    .find(@"h1+*+ul li")
    .forEach(^(SFElement *elem)
    {
        NSLog(@"li:text=%@", elem.text);
    });
}
```

Available CSS Selectors
-------

##### 基本

| 表記      | 意味                  | 例                   |
| --------- |:---------------------:|:--------------------:|
| E         | 名前がEの要素         | ```<E/>          ``` |
| *         | あらゆる要素          |                      |
| E.x       | xがEのclass           | ```<E class="x"> ``` |
| E#x       | xがEのid              | ```<E id="x">    ``` |
| !E        | Eは選択対象(Subject)  |                      |

##### コンビネーター

| 表記      | 意味                  | 例                            |
| --------- |:---------------------:|:-----------------------------:|
| E   F     | Fの孫要素のE          | ```<E>..<F/>..</E>        ``` |
| E > F     | Fの子要素のE          | ```<E>..<C><F/></C>..</E> ``` |
| E + F     | Fの次の要素F          | ```<E/><F/>               ``` |
| E ~ F     | Fの兄弟要素F          | ```<E/>...<F/>            ``` |
| E /X/ F   | Eは属性XでFのidを参照 | ```<E X="Y"/>...<F id="Y">``` |

##### フィルター

| 表記                           | 意味                              |
| -------------------------------|:---------------------------------:|
| E:nth-{last-}child/of-type(EQ) | EQが表す位置の要素                |
| E:first-child                  | Eは最初の子要素                   |
| E:last-child                   | Eは最後の子要素                   |
| E:only-child/of-type           | Eは唯一の子要素                   |
| E:empty                        | Eは子要素を持たない               |
| E:blank                        | Eは空白のテキストのみ子要素とする |
| E:root                         | Eはドキュメントのルート要素       |
| E[X]                           | Eは属性値Xをもつ                  |
| E[X=Y]                         | Eの属性値XはYである               |
| E[X~=Y]                        | Eの属性値XはYを含む(単語扱い)     |
| E[X*=Y]                        | Eの属性値XはYを含む               |
| E[X^=Y]                        | Eの属性値XはYで始まる             |
| E[X$=Y]                        | Eの属性値XはYで終わる             |
| E:matches(X,Y,..)              | Eは条件X,Y,..のどれかに適合する   |
| E:not(X,Y,..)                  | Eは条件X,Y,..のどれにも適合しない |

( **EQ** にはXn+Yなどの形式が利用できます)

詳しくはCSSのリファレンスなどを参照してください。

 - http://www.w3.org/TR/selectors/
 - http://dev.w3.org/csswg/selectors4/

##### サポート予定

| 表記                       | 意味              |
| ---------------------------|:-----------------:|
| E:nth-{last-}match(X of Y) | 調べ中            |
| E:lang(...)                | Eは言語情報をもつ |

他にも対応漏れがあるかもしれません。ご指摘いただけると嬉しいです。

 - UIの挙動に関するセレクターを実装する予定はありません
   - **:hover**, **:visited** など

TODO
-------

 - 32個以上のコンビネーターを一度に処理できない制限をなくす
 - SFNodeListを非同期で扱えるようにする
 - HTMLのタグの解釈を、より既存のブラウザに近く
   - **li**, **script** の扱いなど
 - ```:not(...)``` などで、内側のセレクターの要素指定を省略できるようにする
   - ```:not(*:empty)``` -> ```:not(:empty)```

Version
-------
0.1 (作りかけ)

License
-------
MIT
