import style from "./MainPage.module.css";
import {NavLink} from "react-router-dom";
import React, {Component} from "react";
import {Search} from "../Server_API/request_functions"
import SearchField from "./SearchField";

class MainPage extends Component {
    constructor(props) {
        super(props);
        let q = localStorage.getItem('q');
        if (q === null) {
            q = "stars%3A%3E0";
        }
        let page = Number(localStorage.getItem('page'));
        if (page === null) {
            page = 1;
        }
        this.state = {
            repository: [],
            isLoaded: false,
            q: q,
            page: page
        };
        this.changeRequest = this.changeRequest.bind(this);
        this.changePage = this.changePage.bind(this);
    }

    findReposes() {
        Search(this.state.q, this.state.page).then(response => {
            this.setState({
                repository: response.items,
                isLoaded: true
            });
        });
    }

    async changeRequest(q) {
        await this.setState(
            {
                q: q,
                page: 1,
                isLoaded: false
            }
        );
        localStorage.setItem("q", q);
        localStorage.setItem("page", 1 + "");
        this.findReposes();
    };

    async changePage(page) {
        await this.setState(
            {
                page: page,
                isLoaded: false
            }
        );
        localStorage.setItem("page", page + "");
        this.findReposes();
    };

    componentDidMount() {
        this.findReposes();
    }

    render() {
        const repositoryList = [];
        this.state.repository.forEach((repos) => {
            repositoryList.push(<Repos name={repos.name} stars={repos.stargazers_count} commit_date={repos.pushed_at}
                                       url={repos.html_url} owner={repos.owner.login} repos={repos.name}/>);
        });
        if (this.state.isLoaded) {
            return (
                <div className={style.Wrapper}>
                    <p className={style.Title}>GitHub Dashboard</p>
                    <SearchField searchHangler={this.changeRequest}/>
                    <div className={style.reposListWrapper}>
                        {repositoryList}
                    </div>
                    <Paginator changePage={this.changePage}
                               currentPage={this.state.page === null ? 1 : this.state.page}/>
                </div>
            );
        } else {
            return (
                <div className={style.Loading}>Loading . . .</div>
            )
        }
    };
}

function Repos(props) {
    let pathToRepos = "repository/" + props.owner + "/" + props.repos;
    let str = props.commit_date, reg = /\d+/g;
    if (str !== null) {
        str = str.match(reg);
    } else {
        str = [0, 0, 0, 0, 0, 0]
    }
    return (
        <div className={style.ReposBlock}>
            <NavLink to={pathToRepos} className={style.LinkToReposCard}>
                {props.name}
            </NavLink>
            <br/>
            <p className={style.Date}>Последний коммит
                был {str[2] + "." + str[1] + "." + str[0] + " " + str[3] + ":" + str[4] + ":" + str[5]}</p>
            <p className={style.StarsNumber}>{props.stars} звезд у репозитория</p>
            <a href={props.url} target="_blank" className={style.LinkToRepos}>Перейти к репозиторию</a>
        </div>
    )
}

class Paginator extends Component {
    constructor(props) {
        super(props);
        this.state = {
            items: [{id: 1, isActive: 1 === this.props.currentPage},
                {id: 2, isActive: 2 === this.props.currentPage},
                {id: 3, isActive: 3 === this.props.currentPage},
                {id: 4, isActive: 4 === this.props.currentPage},
                {id: 5, isActive: 5 === this.props.currentPage}]
        }
    }

    pagination = e => {
        this.props.changePage(Number(e.target.innerText));
        this.setState({
            items: this.state.items.map(item => ({
                id: item.id,
                isActive: Number(e.target.innerText) === item.id
            }))
        })
    };

    render() {
        return (
            <div className={style.Paginator}>
                {
                    this.state.items.map(item =>
                        <div
                            style={{backgroundColor: item.isActive ? 'grey' : 'white'}}
                            className={style.PaginatorItem}
                            id={item.id}
                            onClick={this.pagination}
                        >
                            <label className={style.PaginatorLabel}>{item.id}</label>
                        </div>
                    )
                }
            </div>
        );
    }
}

export default MainPage;