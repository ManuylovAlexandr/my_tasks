import React, {Component} from "react";
import style from "./SearchField.module.css";

class SearchField extends Component {
    constructor(props) {
        super(props);
    }

    submitHandler = event => {
        event.preventDefault();
    };

    buttonHandler = event => {
        let s = document.getElementById("search_input").value;
        if (s === "") {
            s = "stars%3A%3E0";
        }
        this.props.searchHangler(s)
    };

    componentDidMount() {
        let q = localStorage.getItem('q');
        if (q === "stars%3A%3E0" || q === null){
            q = null;
        }
        document.getElementById("search_input").value = q;
    }

    render() {
        return (
            <form className={style.InputForm} onSubmit={this.submitHandler}>
                <div className={style.Search} id="search_field">
                    <button className={style.SearchButton} onClick={this.buttonHandler}>
                        Найти
                    </button>
                    <input id="search_input" className={style.SearchInput}
                           placeholder="Какие репозитории вы ищете?"
                           type="search"/>
                </div>
            </form>
        )
    }
}

export default SearchField;